#ifndef UTILS_H
#define UTILS_H

#include "defines.h"
#include "z80.h"

#include <type_traits>
#include <limits>
#include <assert.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

std::string readFileToString(std::string filename);

// Take two bytes (Low, High) and create word
#define CREATE_WORD(L, H) (((uint16_t) L) | (((uint16_t) H) << 8))

// Used to break out of code blocks
#define SKIPPABLE for (int i = 0; i == 0; i = 1)

// Split a string to vector using whitespace as delimiter
std::vector<std::string> splitByWhitespace(std::string str);

// Circular bit rotation left
template <typename INT>
constexpr INT rol(INT val)
{
    static_assert(std::is_unsigned<INT>::value,
                  "Rotate Left only makes sense for unsigned types.");
    return (val << 1) | (val >> (sizeof(INT)*CHAR_BIT-1));
}

// Circular bit rotation right
template <typename INT>
constexpr INT ror(INT val)
{
    static_assert(std::is_unsigned<INT>::value,
                  "Rotate Right only makes sense for unsigned types.");
    return (val >> 1) | (val << (sizeof(INT)*CHAR_BIT-1));
}

// Circular bit rotation left through carry bit
template <typename INT>
constexpr INT rolc(INT& val, bool carry)
{
    static_assert(std::is_unsigned<INT>::value,
                  "Rotate Left only makes sense for unsigned types.");
    bool carryOld = carry;
    carry = (bool) (val >> (sizeof(INT)*CHAR_BIT-1));
    val = (val << 1) | (carryOld & 0x01);
    return carry;
}


// Circular bit rotation right through carry bit
template <typename INT>
constexpr INT rorc(INT& val, bool carry)
{
    static_assert(std::is_unsigned<INT>::value,
                  "Rotate Right only makes sense for unsigned types.");
    bool carryOld = carry;
    carry = (bool) (val & 0x01);
    val = (val >> 1) | ((carryOld & 0x01) << (sizeof(INT)*CHAR_BIT-1));
    return carry;
}

// SLA instruction
template <typename INT>
constexpr void sla(INT& val, Z80Registers* r, bool sll = false)
{
    static_assert(std::is_unsigned<INT>::value,
                  "SLA only makes sense for unsigned types.");
    r->AF.bytes.low.CF = (bool) (val >> (sizeof(INT)*CHAR_BIT-1));
    val = val << 1;
    if (sll) { val |= 1; }
    r->AF.bytes.low.SF = (bool)(val >> 7);
    r->AF.bytes.low.ZF = val == 0;
    r->AF.bytes.low.HF = false;
    r->AF.bytes.low.PF = hasEvenParity(val);
    r->AF.bytes.low.NF = false;
}

// SRA instruction
template <typename INT>
constexpr void sra(INT& val, Z80Registers* r)
{
    static_assert(std::is_unsigned<INT>::value,
                  "SRA only makes sense for unsigned types.");
    r->AF.bytes.low.CF = (bool) (val & 0x01);
    uint8_t leftBit =  val & (1 << (sizeof(INT)*CHAR_BIT-1));
    val = val >> 1;
    val &= 0x7F;
    val |= leftBit;
    r->AF.bytes.low.SF = (bool)(val >> 7);
    r->AF.bytes.low.ZF = val == 0;
    r->AF.bytes.low.HF = false;
    r->AF.bytes.low.PF = hasEvenParity(val);
    r->AF.bytes.low.NF = false;
}

// SRL instruction
template <typename INT>
constexpr void srl(INT& val, Z80Registers* r)
{
    static_assert(std::is_unsigned<INT>::value,
                  "SRL only makes sense for unsigned types.");
    r->AF.bytes.low.CF = (bool) (val & 0x01);
    val = val >> 1;
    r->AF.bytes.low.SF = (bool)(val >> 7);
    r->AF.bytes.low.ZF = val == 0;
    r->AF.bytes.low.HF = false;
    r->AF.bytes.low.PF = hasEvenParity(val);
    r->AF.bytes.low.NF = false;
}

// Sign of val
template <typename T>
int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

// Return the overflow flag for add(a, b)
template <typename INT>
constexpr bool detectOverflow(INT a, INT b)
{
    static_assert(std::is_signed<INT>::value,
                    "Overflow is only detected on signed values.");

    if ( (sgn<INT>(a) != sgn<INT>(b)) || (a == 0 || b == 0) )
    {
        return false;
    }

    if ( sgn<INT>(a+b) != sgn<INT>(a) )
    {
        return true;
    }

    return false;
}

#define CARRY               0x01
#define HALF_CARRY          0x02
#define OVERFLOW_PARITY     0x04
#define SIGN                0x08
#define ZERO                0x10
#define HALF_BORROW         0x20
#define BORROW              0x40

#define CARRY_BOTH          (CARRY | HALF_CARRY)
#define BORROW_BOTH         (BORROW | HALF_BORROW)

#define INC8                (HALF_CARRY | SIGN | ZERO)
#define INC16               (0x00)
#define DEC8                (SIGN | ZERO | HALF_BORROW)
#define DEC16               (0x00)
#define ADD16               (CARRY | HALF_CARRY)
#define ADC16               (SIGN | ZERO | CARRY | HALF_CARRY | OVERFLOW_PARITY)
#define ADD8                (SIGN | ZERO | HALF_CARRY | OVERFLOW_PARITY | CARRY)
#define SUB8                (SIGN | ZERO | HALF_BORROW | OVERFLOW_PARITY | BORROW)
#define SUB8_NOBORROW       (SIGN | ZERO | HALF_BORROW | OVERFLOW_PARITY)
#define SUB16               (SIGN | ZERO | HALF_BORROW | OVERFLOW_PARITY | BORROW)
#define NEG8                (SIGN | ZERO | HALF_BORROW)

// TODO: refactor
// Add two integers, generate selected flags
template <typename INT>
constexpr INT add(INT a, INT b, Z80Registers* r, uint8_t flags, bool useCarryIn = false, bool useBorrowIn = false)
{
    static_assert(std::numeric_limits<INT>::is_integer,
                  "Only integer types allowed in add().");
    //Invalid flags: CARRY and BORROW both set.
    assert(!( (flags & CARRY) && (flags & BORROW) ));
    //Invalid flags: HALF_CARRY and HALF_BORROW both set.
    assert(!( (flags & HALF_CARRY) && (flags & HALF_BORROW) ));

    int typeSize = sizeof(INT) * CHAR_BIT;
    typedef std::make_signed<INT>::type INT_signed;

    INT result;
    INT carryOut;

    bool carryIn = (useCarryIn || useBorrowIn) ? (r->AF.bytes.low.CF) : false;

    if (carryIn)
    {
        carryOut = (a >= std::numeric_limits<INT>::max() - b);
        if (!useBorrowIn) { result = a + b + 1; }
        else { result = a + b - 1; }
    }
    else
    {
        carryOut = (a > std::numeric_limits<INT>::max() - b);
        result = a + b;
    }

    if (flags & CARRY)
    {
        r->AF.bytes.low.CF = (bool)carryOut;
    }
    else if (flags & BORROW)
    {
        INT borrowOut;

        if (carryIn)
        {
            INT bb = ~(b-1);       // get B before two's complement'                
            borrowOut = ((unsigned) bb ) > ((unsigned) a );
            INT r = a - bb;
            borrowOut = borrowOut || (((unsigned) (carryIn & 0x1) ) > ((unsigned) r ));
        }
        else
        {
            INT bb = ~(b-1);       // get B before two's complement'
            borrowOut = ((unsigned) bb) > ((unsigned) a );
        }
        
        
        r->AF.bytes.low.CF = (bool)borrowOut;
    }

    if (flags & OVERFLOW_PARITY)
    {
        r->AF.bytes.low.PF = detectOverflow<INT_signed>(*reinterpret_cast<INT_signed*>(&a),
                                             *reinterpret_cast<INT_signed*>(&b));
    }
    if (flags & HALF_CARRY)
    {
        INT halfCarryOut;
        if ( typeSize == 8 )
        {
            if (carryIn)
            {
                halfCarryOut = ((a & 0xF) >= 0xF - (b & 0xF));
            }
            else
            {
                halfCarryOut = ((a & 0xF) > 0xF - (b & 0xF));
            }
        }
        else
        {
            if (carryIn)
            {
                halfCarryOut = ((a & 0xFFF) >= 0xFFF - (b & 0xFFF));
            }
            else
            {
                halfCarryOut = ((a & 0xFFF) > 0xFFF - (b & 0xFFF));
            }
        }
        r->AF.bytes.low.HF = (bool)halfCarryOut;
    }
    else if (flags & HALF_BORROW)
    {
        INT halfBorrowOut;

        if ( typeSize == 8 )
        {
            if (carryIn)
            {
                INT bb = ~(b-1);       // get B before two's complement'                
                halfBorrowOut = ((unsigned) (bb & 0xF)) > ((unsigned) (a & 0xF));
                INT r = a - bb;
                halfBorrowOut = halfBorrowOut || ( ((unsigned) (carryIn & 0x1)) > ((unsigned) (r & 0xF)));
            }
            else
            {
                INT bb = ~(b-1);       // get B before two's complement'
                halfBorrowOut = ((unsigned) (bb & 0xF)) > ((unsigned) (a & 0xF));
            }
        }
        else
        {
            if (carryIn)
            {
                INT bb = ~(b-1);       // get B before two's complement'                
                halfBorrowOut = ((unsigned) (bb & 0xFFF)) > ((unsigned) (a & 0xFFF));
                INT r = a - bb;
                halfBorrowOut = halfBorrowOut || (((unsigned) (carryIn & 0x1)) > ((unsigned) (r & 0xFFF)));
            }
            else
            {
                INT bb = ~(b-1);       // get B before two's complement'
                halfBorrowOut = ((unsigned) (bb & 0xFFF)) > ((unsigned) (a & 0xFFF));
            }
        }
        r->AF.bytes.low.HF = (bool)halfBorrowOut;
    }
    if (flags & SIGN)
    {
        r->AF.bytes.low.SF = (bool) ( (result >> (typeSize - 1)) & 0x01 );
    }
    if (flags & ZERO)
    {
        r->AF.bytes.low.ZF = !((bool) result);
    }

    return result;
}

// Set undocumented flag bits 3 and 5 based on result of operation
template <typename INT>
constexpr void setUndocumentedFlags(INT result, Z80Registers* r)
{
    r->AF.bytes.low.XF = (bool) ( (result >> 3) & 0x01 );
    r->AF.bytes.low.YF = (bool) ( (result >> 5) & 0x01 );
}

// Returns true if x has even parity (even number of 1s in binary)
template <typename INT>
bool hasEvenParity(INT x)
{
    int count = 0;

    for (int i = 0; i < (sizeof(INT)*CHAR_BIT); i++)
    {
        if ( x & (1 << i) ) { count++; }
    }

    if ( count % 2 ) { return false; }

    return true;
}

bool daaCarry(bool C, uint8_t A);
bool daaHalfCarry(bool N, bool H, uint8_t A);

// Decimal adjust instruction
// Used for BCD number arithmetics
inline void daa(Z80Registers* r)
{
    uint8_t A = r->AF.bytes.high;
    bool H = r->AF.bytes.low.HF;
    bool C = r->AF.bytes.low.CF;
    bool N = r->AF.bytes.low.NF;

    bool newCarry = daaCarry(C, A);
    bool newHalfCarry = daaHalfCarry(N, H, A);

    uint8_t adjust = 0;

    uint8_t oldA = A;

    if ( ((A & 0xF) > 9) || H )
    {
        A = ( N ) ? A -= 0x06 : A += 0x06;
    }
    // if ( (A & 0xF0) > 0x90 || C )
    if ( (oldA > 0x99) || C )
    {
        A = ( N ) ? A -= 0x60 : A += 0x60;
    }

    r->AF.bytes.high = A;
    r->AF.bytes.low.CF = newCarry;
    r->AF.bytes.low.HF = newHalfCarry;
    r->AF.bytes.low.SF = A >> 7;
    setUndocumentedFlags(A, r);
    r->AF.bytes.low.ZF = A == 0;
    r->AF.bytes.low.PF = hasEvenParity(A);
}

// Carry flag after DAA operation
inline bool daaCarry(bool C, uint8_t A)
{
    if (C) { return true; }
    if ( (A & 0xF) < 10 && (A & 0xF0) < 0xA0 ) { return false; }
    if ( (A & 0xF) > 9 && (A & 0xF0) < 0x90 ) { return false; }
    return true;
}

// Half carry flag after DAA operation
inline bool daaHalfCarry(bool N, bool H, uint8_t A)
{
    if (!N)
    {
        if ((A & 0xF) < 10) { return false; }
        else { return true; }
    }
    else 
    {
        if (N && !H) { return false; }
        if ((A & 0xF) > 5 ) { return false; }
        return true;
    }
}

template <typename INT>
INT and(INT a, INT b, Z80Registers* r)
{
    a = a & b;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.SF = (bool) (a >> 7);
    r->AF.bytes.low.ZF = a == 0;
    r->AF.bytes.low.HF = true;
    r->AF.bytes.low.CF = false;
    r->AF.bytes.low.PF = hasEvenParity(a);
    return a;
}

template <typename INT>
INT xor(INT a, INT b, Z80Registers* r)
{
    a = a ^ b;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.SF = (bool) (a >> 7);
    r->AF.bytes.low.ZF = a == 0;
    r->AF.bytes.low.HF = false;
    r->AF.bytes.low.CF = false;
    r->AF.bytes.low.PF = hasEvenParity(a);
    return a;    
}

template <typename INT>
INT or(INT a, INT b, Z80Registers* r)
{
    a = a | b;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.SF = (bool) (a >> 7);
    r->AF.bytes.low.ZF = a == 0;
    r->AF.bytes.low.HF = false;
    r->AF.bytes.low.CF = false;
    r->AF.bytes.low.PF = hasEvenParity(a);
    return a;    
}

enum class RetCondition { NZ = 0, Z, NC, C, PO, PE, P, M };

// RET cc instructions
inline void retc(Z80Registers* r, Spectrum48KMemory* m,  RetCondition c )
{
    bool condition = false;
    switch (c)
    {
        case RetCondition::NZ:  condition = !(r->AF.bytes.low.ZF);  break;
        case RetCondition::Z:   condition = r->AF.bytes.low.ZF;     break;
        case RetCondition::NC:  condition = !(r->AF.bytes.low.CF);  break;
        case RetCondition::C:   condition = r->AF.bytes.low.CF;     break;
        case RetCondition::PO:  condition = !(r->AF.bytes.low.PF);  break;
        case RetCondition::PE:  condition = r->AF.bytes.low.PF;     break;
        case RetCondition::P:   condition = !(r->AF.bytes.low.SF);  break;
        case RetCondition::M:   condition = r->AF.bytes.low.SF;     break;
        default:                assert(false);                      break;
    }

    if (condition)
    {
        r->PC = 0;
        r->PC |= (*m)[r->SP];
        r->SP++;
        r->PC |= (*m)[r->SP] << 8;
        r->SP++;
    }
}

// CALL cc,nn instructinos
inline void callc(Z80Registers* r, Spectrum48KMemory* m, RetCondition c, uint16_t nn)
{
    bool condition = false;
    switch (c)
    {
        case RetCondition::NZ:  condition = !(r->AF.bytes.low.ZF);  break;
        case RetCondition::Z:   condition = r->AF.bytes.low.ZF;     break;
        case RetCondition::NC:  condition = !(r->AF.bytes.low.CF);  break;
        case RetCondition::C:   condition = r->AF.bytes.low.CF;     break;
        case RetCondition::PO:  condition = !(r->AF.bytes.low.PF);  break;
        case RetCondition::PE:  condition = r->AF.bytes.low.PF;     break;
        case RetCondition::P:   condition = !(r->AF.bytes.low.SF);  break;
        case RetCondition::M:   condition = r->AF.bytes.low.SF;     break;
        default:                assert(false);                      break;
    }

    if (condition)
    {
        r->SP--;
        (*m)[r->SP] = (r->PC) >> 8;
        r->SP--;
        (*m)[r->SP] = (r->PC) & 0xFF;
        r->PC = nn;
    }
}

#endif