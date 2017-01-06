#pragma once

#include <stdint.h>
#include <unordered_map>
#include <tuple>
#include <vector>

#include "instruction.h"
#include "utils.h"

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
    }
};
}

// Instruction lambda signature
#define INST [](Z80* z, Spectrum48KMemory* m, std::vector<uint8_t> d)

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

    // LD (BC),A
    oc = {0,0,0x0002};
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->BC.word] = z->getRegisters()->AF.bytes.high;
        }
    };
    instructions[oc] = i;

    // INC BC
    oc = {0,0,0x0003};
    i = { 6, 6, 0, INST{ 
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, 1, r, INC16);
        } 
    };
    instructions[oc] = i;

    // INC B
    oc = {0,0,0x0004};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x7F) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // DEC B
    oc = {0,0,0x0005};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x80) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        }
    };
    instructions[oc] = i;

    // LD B,n
    oc = {0,0,0x0006};
    i = { 7, 7, 1, INST{ z->getRegisters()->BC.bytes.high = d[0]; } };
    instructions[oc] = i;

    // RLCA
    oc = {0,0,0x0007};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high >> 7) & 0x01);
            r->AF.bytes.high = rol<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        }
    };
    instructions[oc] = i;

    // EX AF, AF'
    oc = {0,0,0x0008};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->AFx.word;
            r->AFx.word = r->AF.word;
            r->AF.word = tmp;
        }
    };
    instructions[oc] = i;

    // ADD HL,BC
    oc = {0,0,0x0009};
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add(r->HL.word, r->BC.word, r, ADD16);
            setUndocumentedFlags(r->HL.word, r);
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // LD A,(BC)
    oc = {0,0,0x000A};
    i = { 7, 7, 1, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->BC.word];
        }
    };
    instructions[oc] = i;

    // DEC BC
    oc = {0,0,0x000B};
    i = { 6, 6, 0, INST{ 
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, DEC16);
        }
    };
    instructions[oc] = i;

    // INC C
    oc = {0,0,0x000C};
    i = { 4, 4, 0, INST{ 
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x7F) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // DEC C
    oc = {0,0,0x000D};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x80) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        }
    };
    instructions[oc] = i;

    // LD C,n
    oc = {0,0,0x000E};
    i = { 7, 7, 1, INST{ z->getRegisters()->BC.bytes.low = d[0]; } };
    instructions[oc] = i;

    // RRCA
    oc = {0,0,0x000F};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high) & 0x01);
            r->AF.bytes.high = ror<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        }
    };
    instructions[oc] = i;

    return instructions;
}