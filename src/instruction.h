#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>
#include <vector>
#include <string>

class Z80;

#include "memory.h"

// Type of a machine cycle, used for contention timing
// M1R      M1 cycle
// MRD      Memory read
// MWR      Memory write
// IOR      I/O read
// IOW      I/O write
// NON      Internal computation
enum class MachineCycleType { UNUSED, M1R, MRD, MWR, IOR, IOW, NON };

struct Instruction {
    int cycles;                 // Number of clock cycles to execute
    int cyclesOnJump;           // Number of clock cycles to execute if jump is taken
    int numDataBytes;           // Number of data bytes after the instrution

    // Execute this instruction
    void (*execute)(Z80*, Spectrum48KMemory*, std::vector<uint8_t>);

    int cntMachineCycles;       // Number of machine cycles

    MachineCycleType machineCycles[7];  // Types of machine cycles of this instruction
    int machineCycleTimes[7];   // T cycles of each machine cycle
    std::string mnemonic;
};

#endif