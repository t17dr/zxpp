#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>
//#include <unordered_map>
#include <tuple>
#include <vector>
#include <array>

#include "defines.h"
#include "instruction.h"

// Instruction opcode has up to 3 bytes
typedef std::tuple<uint8_t, uint8_t, uint8_t> opcode;

// Hash for type opcode
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
        //return ((size_t)(std::get<0>(k))) ^ (((size_t)(std::get<1>(k))) << 8) ^ (((size_t)(std::get<2>(k))) << 16);

        /*uint8_t a = 251, b = 199, c = 47, d = 101;

        return ( a + b*std::get<0>(k) + c*std::get<1>(k) + d*std::get<2>(k) );*/
    }
};
}

// Instruction lambda signature
#define INST [](Z80* z, Spectrum48KMemory* m, std::vector<uint8_t> d)

// Create the instruction set
std::array<Instruction, NUM_INSTRUCTIONS> z80InstructionSet();

#endif