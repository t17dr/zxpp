#pragma once

#include <stdint.h>
#include <unordered_map>
#include <tuple>
#include <vector>

#include "instruction.h"

// Instruction opcode has up to 3 bytes
typedef std::tuple<uint8_t, uint8_t, uint8_t> opcode;

// Hash class for type opcode
namespace std {
template <>
struct hash<opcode>{
    std::size_t operator()(const opcode& k) const
    {
        using std::hash;

        size_t a = ( hash<uint8_t>()( std::get<0>(k) ) );
        size_t b = ( ( hash<uint8_t>()( std::get<1>(k) ) << 1) >> 1 );
        size_t c = ( hash<uint8_t>()( std::get<2>(k) ) << 1);

        return a ^ b ^ c;
    }
};
}

// Instruction lambda signature
#define INST [](Z80* z, Spectrum48KMemory* m, std::vector<uint8_t> d)

// Take two bytes (Low, High) and create word
#define CREATE_WORD(L, H) (((uint16_t) L) | (((uint16_t) H) << 8))

std::unordered_map<opcode, Instruction> z80InstructionSet()
{
    std::unordered_map<opcode, Instruction> instructions;
    // NOP
    opcode oc = {0,0,0x0000};
    Instruction i = { 4, 4, 0, INST{ ; } };
    
    instructions[oc] = i;
    // LD BC,nn
    oc = {0,0,0x0001};
    i = { 10, 10, 2, INST{ z->getRegisters()->BC.word = CREATE_WORD(d[0], d[1]); } };
    instructions[oc] = i;

    return instructions;
}