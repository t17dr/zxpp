#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>
#include <vector>

//#include "Z80.h"
class Z80;
//struct Z80Registers;

#include "memory.h"

struct Instruction {
    int cycles;                 // Number of clock cycles to execute
    int cyclesOnJump;           // Number of clock cycles to execute if jump is taken
    int numDataBytes;           // Number of data bytes after the instrution

    // Execute this instruction
    void (*execute)(Z80*, Spectrum48KMemory*, std::vector<uint8_t>);
};

#endif