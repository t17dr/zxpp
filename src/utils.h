#pragma once

#include <type_traits>
#include <limits>
#include <assert.h>

// Take two bytes (Low, High) and create word
#define CREATE_WORD(L, H) (((uint16_t) L) | (((uint16_t) H) << 8))

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

    if ( sgn<INT>(a+b) != a )
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

// Add two integers, generate selected flags
template <typename INT>
constexpr INT add(INT a, INT b, Z80Registers* r, uint8_t flags, bool useCarryIn = false)
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

    bool carryIn = (useCarryIn) ? (r->AF.bytes.low.CF) : false;

    if (carryIn)
    {
        carryOut = (a >= std::numeric_limits<INT>::max() - b);
        result = a + b + 1;
    }
    else
    {
        carryOut = (a > std::numeric_limits<INT>::max() - b);
        result = a + b;
    }
    // carryIns = result ^ a ^ b;
    // halfCarryOut = (carryIns >> 4) & 1;

    if (flags & CARRY)
    {
        r->AF.bytes.low.CF = (bool)carryOut;
    }
    else if (flags & BORROW)
    {
        // TODO: neodzkouseny
        INT borrowOut;
        borrowOut = !a && b;
        r->AF.bytes.low.CF = (bool)borrowOut;
    }

    if (flags & OVERFLOW)
    {
        r->AF.bytes.low.PF = detectOverflow<INT_signed>(*reinterpret_cast<INT_signed*>(&a),
                                             *reinterpret_cast<INT_signed*>(&b));
    }
    if (flags & HALF_CARRY)
    {
        INT halfCarryOut;
        if ( typeSize == 8 )
        {
            // halfCarryOut = (((a & 0xF) + (b & 0xF) + (INT)carryIn) & 0x10) >> 4;
            // TODO: neodzkouseny
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
            halfBorrowOut = ((!(a & 0xF)) && (b & 0xF));
        }
        else
        {
            // TODO: neodzouseny
            halfBorrowOut = ((!(a & 0xFFF)) && (b & 0xFFF));
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
