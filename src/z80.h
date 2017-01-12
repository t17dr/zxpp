#ifndef Z80_H
#define Z80_H

#include <stdint.h>

#define CLOCK_TIME ( 1.0 / 3500000.0 )

struct Word {                   // Endianness dependent!
    uint8_t low;
    uint8_t high;
};

struct WordFlags {
    union {
        uint8_t byte;           // Accumulator
        struct {                // Flags
            bool CF : 1;        // Carry
            bool NF : 1;        // Last operation was addition (0) or subtraction (1)
            bool PF : 1;        // Parity or signed overflow flag
            bool XF : 1;        // Undocumented: Copy of bit 3 of the result
            bool HF : 1;        // Half carry
            bool YF : 1;        // Undocumented: Copy of bit 5 of the result
            bool ZF : 1;        // Zero flag
            bool SF : 1;        // Is result negative? (Copy of MSB)
        };
    } low;
    uint8_t high;
};

struct Z80Registers {
    uint16_t PC;                // Program counter
    uint16_t SP;                // Stack pointer

    // Index registers
    union {
        uint16_t word;
        Word bytes;
    } IX;
    union {
        uint16_t word;
        Word bytes;
    } IY;

    union {                     // Interrupt register and memory refresh register
        uint16_t word;
        Word bytes;
    } IR;

    // Accumulator and flags
    union {
        uint16_t word;
        WordFlags bytes;
    } AF;

    // General purpose registers
    union {
        uint16_t word;
        Word bytes;
    } BC;

    union {
        uint16_t word;
        Word bytes;
    } DE;

    union {
        uint16_t word;
        Word bytes;
    } HL;

    // Alternate register set
    union {
        uint16_t word;
        WordFlags bytes;
    } AFx;

    union {
        uint16_t word;
        Word bytes;
    } BCx;

    union {
        uint16_t word;
        Word bytes;
    } DEx;

    union {
        uint16_t word;
        Word bytes;
    } HLx;
};

struct Z80IOPorts {
    uint8_t ports[0xFF+1];

    inline uint8_t& operator[](uint16_t i)
    {
        return ports[i];
    }

    inline const uint8_t& operator[](uint16_t i) const
    {
        return ports[i];
    }

    uint8_t* begin() { return ports; }
    uint8_t* end()   { return ports + 0xff; }

    uint8_t const* cbegin() const { return ports; }
    uint8_t const* cend()   const { return ports + 0xff; }
    uint8_t const* begin()  const { return cbegin(); }
    uint8_t const* end()    const { return cend(); }
};

class Z80 {
    public:
        Z80();
        void init();                    // Set power-on defaults
        Z80Registers* getRegisters();
        Z80IOPorts* getIoPorts();
        void halt();
    private:
        Z80Registers m_registers;
        Z80IOPorts m_ioPorts;
        bool m_IFF1;                    // Interrupt flip-flops
        bool m_IFF2;

        // TODO: execute NOPs while halted
        bool m_isHalted;
        bool m_isWaiting;               // WAIT pin active
};

#endif