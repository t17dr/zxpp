/*
    This file was automatically generated from a file that was manually generated
    by an idiot programmer. If you are looking for inspiration on your own ZX Spectrum
    emulator, don't do this, that was a bad idea (the manual writing of all opcode variations).

    More information in instructions_preprocess.py and the original file instructions.cpp.orig
*/

#include "instructions.h"

#include "utils.h"

std::shared_ptr<std::array<Instruction, NUM_INSTRUCTIONS>> z80InstructionSet()
{
    // Must use constructor to be zero initialized (omitted NOPs)
    std::shared_ptr<std::array<Instruction, NUM_INSTRUCTIONS>> instructions 
        = std::make_shared<std::array<Instruction, NUM_INSTRUCTIONS>>();

    // NOP
    int oc = 0;
    Instruction i = { 4, 4, 0, INST{ ; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "NOP"
    };    (*instructions)[oc] = i;

    // LD BC,nn
    oc = 1;
    i = { 10, 10, 2, INST{ z->getRegisters()->BC.word = CREATE_WORD(d[0], d[1]); },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "LD BC,nn"
    };    (*instructions)[oc] = i;

    // LD (BC),A
    oc = 2;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->BC.word] = z->getRegisters()->AF.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (BC),A"
       };
    (*instructions)[oc] = i;

    // INC BC
    oc = 3;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, 1, r, INC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "INC BC"
       };
    (*instructions)[oc] = i;

    // INC B
    oc = 4;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x7F) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "INC B"
       };
    (*instructions)[oc] = i;

    // DEC B
    oc = 5;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x80) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DEC B"
       };
    (*instructions)[oc] = i;

    // LD B,n
    oc = 6;
    i = { 7, 7, 1, INST{ z->getRegisters()->BC.bytes.high = d[0]; },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD B,n"
    };    (*instructions)[oc] = i;

    // RLCA
    oc = 7;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high >> 7) & 0x01);
            r->AF.bytes.high = rol<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "RLCA"
       };
    (*instructions)[oc] = i;

    // EX AF, AF'
    oc = 8;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->AFx.word;
            r->AFx.word = r->AF.word;
            r->AF.word = tmp;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "EX AF, AF'"
       };
    (*instructions)[oc] = i;

    // ADD HL,BC
    oc = 9;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add(r->HL.word, r->BC.word, r, ADD16);
            setUndocumentedFlags(r->HL.word, r);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADD HL,BC"
       };
    (*instructions)[oc] = i;

    // LD A,(BC)
    oc = 10;
    i = { 7, 7, 0, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->BC.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD A,(BC)"
       };
    (*instructions)[oc] = i;

    // DEC BC
    oc = 11;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, DEC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "DEC BC"
       };
    (*instructions)[oc] = i;

    // INC C
    oc = 12;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x7F) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "INC C"
       };
    (*instructions)[oc] = i;

    // DEC C
    oc = 13;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x80) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DEC C"
       };
    (*instructions)[oc] = i;

    // LD C,n
    oc = 14;
    i = { 7, 7, 1, INST{ z->getRegisters()->BC.bytes.low = d[0]; },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD C,n"
    };    (*instructions)[oc] = i;

    // RRCA
    oc = 15;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high) & 0x01);
            r->AF.bytes.high = ror<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "RRCA"
       };
    (*instructions)[oc] = i;

    // DJNZ d
    oc = 16;
    i = { 8, 13, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            if (r->BC.bytes.high != 0)
            {
                r->PC += (int8_t) d[0];
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 5, 0, 0, 0, 0 },
        "DJNZ d"
       };
    (*instructions)[oc] = i;

    // LD DE,nn
    oc = 17;
    i = { 10, 10, 2, INST{ z->getRegisters()->DE.word = CREATE_WORD(d[0], d[1]); },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "LD DE,nn"
    };    (*instructions)[oc] = i;

    // LD (DE),A
    oc = 18;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->DE.word] = z->getRegisters()->AF.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (DE),A"
       };
    (*instructions)[oc] = i;

    // INC DE
    oc = 19;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, 1, r, INC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "INC DE"
       };
    (*instructions)[oc] = i;

    // INC D
    oc = 20;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x7F) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "INC D"
       };
    (*instructions)[oc] = i;

    // DEC D
    oc = 21;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x80) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DEC D"
       };
    (*instructions)[oc] = i;

    // LD D,n
    oc = 22;
    i = { 7, 7, 1, INST{ z->getRegisters()->DE.bytes.high = d[0]; },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD D,n"
    };    (*instructions)[oc] = i;

    // RLA
    oc = 23;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "RLA"
       };
    (*instructions)[oc] = i;

    // JR d
    oc = 24;
    i = { 12, 12, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->PC += (int8_t) d[0];
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 5, 0, 0, 0, 0 },
        "JR d"
       };
    (*instructions)[oc] = i;

    // ADD HL,DE
    oc = 25;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add(r->HL.word, r->DE.word, r, ADD16);
            setUndocumentedFlags(r->HL.word, r);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADD HL,DE"
       };
    (*instructions)[oc] = i;

    // LD A,(DE)
    oc = 26;
    i = { 7, 7, 0, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->DE.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD A,(DE)"
       };
    (*instructions)[oc] = i;

    // DEC DE
    oc = 27;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, -1, r, DEC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "DEC DE"
       };
    (*instructions)[oc] = i;

    // INC E
    oc = 28;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x7F) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "INC E"
       };
    (*instructions)[oc] = i;

    // DEC E
    oc = 29;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x80) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DEC E"
       };
    (*instructions)[oc] = i;

    // LD E,n
    oc = 30;
    i = { 7, 7, 1, INST{ z->getRegisters()->DE.bytes.low = d[0]; },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD E,n"
    };    (*instructions)[oc] = i;

    // RRA
    oc = 31;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "RRA"
       };
    (*instructions)[oc] = i;

    // JR NZ,d
    oc = 32;
    i = { 7, 12, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.ZF == false)
            {
                r->PC += (int8_t) d[0];
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 5, 0, 0, 0, 0 },
        "JR NZ,d"
       };
    (*instructions)[oc] = i;

    // LD HL,nn
    oc = 33;
    i = { 10, 10, 2, INST{ z->getRegisters()->HL.word = CREATE_WORD(d[0], d[1]); },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "LD HL,nn"
    };    (*instructions)[oc] = i;

    // LD (nn),HL
    oc = 34;
    i = { 16, 16, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->HL.bytes.low;
            (*m)[nn+1] = z->getRegisters()->HL.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 3, 3, 0, 0 },
        "LD (nn),HL"
       };
    (*instructions)[oc] = i;

    // INC HL
    oc = 35;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, INC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "INC HL"
       };
    (*instructions)[oc] = i;

    // INC H
    oc = 36;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->HL.bytes.high == 0x7F) ? true : false;
            r->HL.bytes.high = add<uint8_t>(r->HL.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "INC H"
       };
    (*instructions)[oc] = i;

    // DEC H
    oc = 37;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->HL.bytes.high == 0x80) ? true : false;
            r->HL.bytes.high = add<uint8_t>(r->HL.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DEC H"
       };
    (*instructions)[oc] = i;

    // LD H,n
    oc = 38;
    i = { 7, 7, 1, INST{ z->getRegisters()->HL.bytes.high = d[0]; },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD H,n"
    };    (*instructions)[oc] = i;

    // DAA
    oc = 39;
    i = { 4, 4, 0, INST{ Z80Registers* r = z->getRegisters(); daa(r); },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DAA"
    };    (*instructions)[oc] = i;

    // JR Z,d
    oc = 40;
    i = { 7, 12, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.ZF == true)
            {
                r->PC += (int8_t) d[0];
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 5, 0, 0, 0, 0 },
        "JR Z,d"
       };
    (*instructions)[oc] = i;

    // ADD HL,HL
    oc = 41;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add(r->HL.word, r->HL.word, r, ADD16);
            setUndocumentedFlags(r->HL.word, r);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADD HL,HL"
       };
    (*instructions)[oc] = i;

    // LD HL,(nn)
    oc = 42;
    i = { 16, 16, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            uint16_t in = CREATE_WORD((*m)[nn], (*m)[nn+1]);
            z->getRegisters()->HL.word = in;
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 3, 3, 0, 0 },
        "LD HL,(nn)"
       };
    (*instructions)[oc] = i;

    // DEC HL
    oc = 43;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, DEC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "DEC HL"
       };
    (*instructions)[oc] = i;

    // INC L
    oc = 44;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->HL.bytes.low == 0x7F) ? true : false;
            r->HL.bytes.low = add<uint8_t>(r->HL.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "INC L"
       };
    (*instructions)[oc] = i;

    // DEC L
    oc = 45;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->HL.bytes.low == 0x80) ? true : false;
            r->HL.bytes.low = add<uint8_t>(r->HL.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DEC L"
       };
    (*instructions)[oc] = i;

    // LD L,n
    oc = 46;
    i = { 7, 7, 1, INST{ z->getRegisters()->HL.bytes.low = d[0]; },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD L,n"
    };    (*instructions)[oc] = i;

    // CPL
    oc = 47;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = ~(r->AF.bytes.high);
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CPL"
       };
    (*instructions)[oc] = i;

    // JR NC,d
    oc = 48;
    i = { 7, 12, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.CF == false)
            {
                r->PC += (int8_t) d[0];
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 5, 0, 0, 0, 0 },
        "JR NC,d"
       };
    (*instructions)[oc] = i;

    // LD SP,nn
    oc = 49;
    i = { 10, 10, 2, INST{ z->getRegisters()->SP = CREATE_WORD(d[0], d[1]); },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "LD SP,nn"
    };    (*instructions)[oc] = i;

    // LD (nn),A
    oc = 50;
    i = { 13, 13, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->AF.bytes.high;
        },
        4, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 3, 0, 0, 0 },
        "LD (nn),A"
       };
    (*instructions)[oc] = i;

    // INC SP
    oc = 51;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = add<uint16_t>(r->SP, 1, r, INC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "INC SP"
       };
    (*instructions)[oc] = i;

    // INC (HL)
    oc = 52;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t byte = (*m)[r->HL.word];
            r->AF.bytes.low.PF = (byte == 0x7F) ? true : false;
            byte = add<uint8_t>(byte, 1, r, INC8);
            (*m)[r->HL.word] = byte;
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "INC (HL)"
       };
    (*instructions)[oc] = i;

    // DEC (HL)
    oc = 53;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t byte = (*m)[r->HL.word];
            r->AF.bytes.low.PF = (byte == 0x80) ? true : false;
            byte = add<uint8_t>(byte, -1, r, DEC8);
            (*m)[r->HL.word] = byte;
            r->AF.bytes.low.NF = true;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "DEC (HL)"
       };
    (*instructions)[oc] = i;

    // LD (HL),n
    oc = 54;
    i = { 10, 10, 1, INST{
            (*m)[z->getRegisters()->HL.word] = d[0];
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "LD (HL),n"
       };
    (*instructions)[oc] = i;

    // SCF
    oc = 55;
    i = { 4, 4, 0, INST{
            z->getRegisters()->AF.bytes.low.CF = true;
            z->getRegisters()->AF.bytes.low.NF = false;
            z->getRegisters()->AF.bytes.low.HF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SCF"
       };
    (*instructions)[oc] = i;

    // JR C,d
    oc = 56;
    i = { 7, 12, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.CF == true)
            {
                r->PC += (int8_t) d[0];
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 5, 0, 0, 0, 0 },
        "JR C,d"
       };
    (*instructions)[oc] = i;

    // ADD HL,SP
    oc = 57;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add(r->HL.word, r->SP, r, ADD16);
            setUndocumentedFlags(r->HL.word, r);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADD HL,SP"
       };
    (*instructions)[oc] = i;

    // LD A,(nn)
    oc = 58;
    i = { 13, 13, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            z->getRegisters()->AF.bytes.high = (*m)[nn];
        },
        4, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 3, 0, 0, 0 },
        "LD A,(nn)"
       };
    (*instructions)[oc] = i;

    // DEC SP
    oc = 59;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = add<uint16_t>(r->SP, -1, r, DEC16);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "DEC SP"
       };
    (*instructions)[oc] = i;

    // INC A
    oc = 60;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->AF.bytes.high == 0x7F) ? true : false;
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "INC A"
       };
    (*instructions)[oc] = i;

    // DEC A
    oc = 61;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->AF.bytes.high == 0x80) ? true : false;
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DEC A"
       };
    (*instructions)[oc] = i;

    // LD A,n
    oc = 62;
    i = { 7, 7, 1, INST{ z->getRegisters()->AF.bytes.high = d[0]; },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD A,n"
    };    (*instructions)[oc] = i;

    // CCF
    oc = 63;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            bool prevCarry = r->AF.bytes.low.CF;
            r->AF.bytes.low.CF = (r->AF.bytes.low.CF) ? false : true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = prevCarry;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CCF"
       };
    (*instructions)[oc] = i;

    // LD B,B
    oc = 64;
    i = { 4, 4, 0, INST{ ; /* Practically a NOP */ },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD B,B"
   };    (*instructions)[oc] = i;

    // LD B,C
    oc = 65;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->BC.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD B,C"
    };    (*instructions)[oc] = i;

    // LD B,D
    oc = 66;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->DE.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD B,D"
    };    (*instructions)[oc] = i;

    // LD B,E
    oc = 67;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->DE.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD B,E"
    };    (*instructions)[oc] = i;

    // LD B,H
    oc = 68;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->HL.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD B,H"
    };    (*instructions)[oc] = i;

    // LD B,L
    oc = 69;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->HL.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD B,L"
    };    (*instructions)[oc] = i;

    // LD B,(HL)
    oc = 70;
    i = { 7, 7, 0, INST{
            z->getRegisters()->BC.bytes.high = (*m)[z->getRegisters()->HL.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD B,(HL)"
       };
    (*instructions)[oc] = i;

    // LD B,A
    oc = 71;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->AF.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD B,A"
    };    (*instructions)[oc] = i;

    // LD C,B
    oc = 72;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->BC.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD C,B"
    };    (*instructions)[oc] = i;

    // LD C,C
    oc = 73;
    i = { 4, 4, 0, INST{ ; /* Practically a NOP */ },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD C,C"
    };    (*instructions)[oc] = i;

    // LD C,D
    oc = 74;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->DE.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD C,D"
    };    (*instructions)[oc] = i;

    // LD C,E
    oc = 75;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->DE.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD C,E"
    };    (*instructions)[oc] = i;

    // LD C,H
    oc = 76;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->HL.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD C,H"
    };    (*instructions)[oc] = i;

    // LD C,L
    oc = 77;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->HL.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD C,L"
    };    (*instructions)[oc] = i;

    // LD C,(HL)
    oc = 78;
    i = { 7, 7, 0, INST{
            z->getRegisters()->BC.bytes.low = (*m)[z->getRegisters()->HL.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD C,(HL)"
       };
    (*instructions)[oc] = i;

    // LD C,A
    oc = 79;
    i = { 4, 4, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->AF.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD C,A"
    };    (*instructions)[oc] = i;

    // LD D,B
    oc = 80;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->BC.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD D,B"
    };    (*instructions)[oc] = i;

    // LD D,C
    oc = 81;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->BC.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD D,C"
    };    (*instructions)[oc] = i;

    // LD D,D
    oc = 82;
    i = { 4, 4, 0, INST{ ; /* Practically a NOP */ },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD D,D"
    };    (*instructions)[oc] = i;

    // LD D,E
    oc = 83;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->DE.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD D,E"
    };    (*instructions)[oc] = i;

    // LD D,H
    oc = 84;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->HL.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD D,H"
    };    (*instructions)[oc] = i;

    // LD D,L
    oc = 85;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->HL.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD D,L"
    };    (*instructions)[oc] = i;

    // LD D,(HL)
    oc = 86;
    i = { 7, 7, 0, INST{
            z->getRegisters()->DE.bytes.high = (*m)[z->getRegisters()->HL.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD D,(HL)"
       };
    (*instructions)[oc] = i;

    // LD D,A
    oc = 87;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->AF.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD D,A"
    };    (*instructions)[oc] = i;

    // LD E,B
    oc = 88;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->BC.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD E,B"
    };    (*instructions)[oc] = i;

    // LD E,C
    oc = 89;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->BC.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD E,C"
    };    (*instructions)[oc] = i;

    // LD E,D
    oc = 90;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->DE.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD E,D"
    };    (*instructions)[oc] = i;

    // LD E,E
    oc = 91;
    i = { 4, 4, 0, INST{; /* Practically a NOP */ },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD E,E"
    };    (*instructions)[oc] = i;

    // LD E,H
    oc = 92;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->HL.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD E,H"
    };    (*instructions)[oc] = i;

    // LD E,L
    oc = 93;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->HL.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD E,L"
    };    (*instructions)[oc] = i;

    // LD E,(HL)
    oc = 94;
    i = { 7, 7, 0, INST{
            z->getRegisters()->DE.bytes.low = (*m)[z->getRegisters()->HL.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD E,(HL)"
       };
    (*instructions)[oc] = i;

    // LD E,A
    oc = 95;
    i = { 4, 4, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->AF.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD E,A"
    };    (*instructions)[oc] = i;

    // LD H,B
    oc = 96;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.high = z->getRegisters()->BC.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD H,B"
    };    (*instructions)[oc] = i;

    // LD H,C
    oc = 97;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.high = z->getRegisters()->BC.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD H,C"
    };    (*instructions)[oc] = i;

    // LD H,D
    oc = 98;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.high = z->getRegisters()->DE.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD H,D"
    };    (*instructions)[oc] = i;

    // LD H,E
    oc = 99;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.high = z->getRegisters()->DE.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD H,E"
    };    (*instructions)[oc] = i;

    // LD H,H
    oc = 100;
    i = { 4, 4, 0, INST{ ; /* Practically a NOP */ },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD H,H"
    };    (*instructions)[oc] = i;

    // LD H,L
    oc = 101;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.high = z->getRegisters()->HL.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD H,L"
    };    (*instructions)[oc] = i;

    // LD H,(HL)
    oc = 102;
    i = { 7, 7, 0, INST{
            z->getRegisters()->HL.bytes.high = (*m)[z->getRegisters()->HL.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD H,(HL)"
       };
    (*instructions)[oc] = i;

    // LD H,A
    oc = 103;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.high = z->getRegisters()->AF.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD H,A"
    };    (*instructions)[oc] = i;

    // LD L,B
    oc = 104;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.low = z->getRegisters()->BC.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD L,B"
    };    (*instructions)[oc] = i;

    // LD L,C
    oc = 105;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.low = z->getRegisters()->BC.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD L,C"
    };    (*instructions)[oc] = i;

    // LD L,D
    oc = 106;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.low = z->getRegisters()->DE.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD L,D"
    };    (*instructions)[oc] = i;

    // LD L,E
    oc = 107;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.low = z->getRegisters()->DE.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD L,E"
    };    (*instructions)[oc] = i;

    // LD L,H
    oc = 108;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.low = z->getRegisters()->HL.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD L,H"
    };    (*instructions)[oc] = i;

    // LD L,L
    oc = 109;
    i = { 4, 4, 0, INST{ ; /* Practically a NOP */ },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD L,L"
    };    (*instructions)[oc] = i;

    // LD L,(HL)
    oc = 110;
    i = { 7, 7, 0, INST{
            z->getRegisters()->HL.bytes.low = (*m)[z->getRegisters()->HL.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD L,(HL)"
       };
    (*instructions)[oc] = i;

    // LD L,A
    oc = 111;
    i = { 4, 4, 0, INST{ z->getRegisters()->HL.bytes.low = z->getRegisters()->AF.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD L,A"
    };    (*instructions)[oc] = i;

    // LD (HL),B
    oc = 112;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->HL.word] = z->getRegisters()->BC.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (HL),B"
       };
    (*instructions)[oc] = i;

    // LD (HL),C
    oc = 113;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->HL.word] = z->getRegisters()->BC.bytes.low;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (HL),C"
       };
    (*instructions)[oc] = i;

    // LD (HL),D
    oc = 114;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->HL.word] = z->getRegisters()->DE.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (HL),D"
       };
    (*instructions)[oc] = i;

    // LD (HL),E
    oc = 115;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->HL.word] = z->getRegisters()->DE.bytes.low;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (HL),E"
       };
    (*instructions)[oc] = i;

    // LD (HL),H
    oc = 116;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->HL.word] = z->getRegisters()->HL.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (HL),H"
       };
    (*instructions)[oc] = i;

    // LD (HL),L
    oc = 117;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->HL.word] = z->getRegisters()->HL.bytes.low;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (HL),L"
       };
    (*instructions)[oc] = i;

    // HALT
    oc = 118;
    i = { 4, 4, 0, INST{
            z->halt();
            (z->getRegisters()->PC)--;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "HALT"
       };
    (*instructions)[oc] = i;

    // LD (HL),A
    oc = 119;
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->HL.word] = z->getRegisters()->AF.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD (HL),A"
       };
    (*instructions)[oc] = i;

    // LD A,B
    oc = 120;
    i = { 4, 4, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->BC.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD A,B"
    };    (*instructions)[oc] = i;

    // LD A,C
    oc = 121;
    i = { 4, 4, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->BC.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD A,C"
    };    (*instructions)[oc] = i;

    // LD A,D
    oc = 122;
    i = { 4, 4, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->DE.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD A,D"
    };    (*instructions)[oc] = i;

    // LD A,E
    oc = 123;
    i = { 4, 4, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->DE.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD A,E"
    };    (*instructions)[oc] = i;

    // LD A,H
    oc = 124;
    i = { 4, 4, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->HL.bytes.high; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD A,H"
    };    (*instructions)[oc] = i;

    // LD A,L
    oc = 125;
    i = { 4, 4, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->HL.bytes.low; },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD A,L"
    };    (*instructions)[oc] = i;

    // LD A,(HL)
    oc = 126;
    i = { 7, 7, 0, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->HL.word];
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "LD A,(HL)"
       };
    (*instructions)[oc] = i;

    // LD A,A
    oc = 127;
    i = { 4, 4, 0, INST{ ; /* Practically a NOP */ },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "LD A,A"
    };    (*instructions)[oc] = i;

    // ADD A,B
    oc = 128;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADD A,B"
       };
    (*instructions)[oc] = i;

    // ADD A,C
    oc = 129;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADD A,C"
       };
    (*instructions)[oc] = i;

    // ADD A,D
    oc = 130;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADD A,D"
       };
    (*instructions)[oc] = i;

    // ADD A,E
    oc = 131;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADD A,E"
       };
    (*instructions)[oc] = i;

    // ADD A,H
    oc = 132;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->HL.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADD A,H"
       };
    (*instructions)[oc] = i;

    // ADD A,L
    oc = 133;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->HL.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADD A,L"
       };
    (*instructions)[oc] = i;

    // ADD A,(HL)
    oc = 134;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, (*m)[z->getRegisters()->HL.word], r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "ADD A,(HL)"
       };
    (*instructions)[oc] = i;

    // ADD A,A
    oc = 135;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->AF.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADD A,A"
       };
    (*instructions)[oc] = i;

    // ADC A,B
    oc = 136;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADC A,B"
       };
    (*instructions)[oc] = i;

    // ADC A,C
    oc = 137;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADC A,C"
       };
    (*instructions)[oc] = i;

    // ADC A,D
    oc = 138;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADC A,D"
       };
    (*instructions)[oc] = i;

    // ADC A,E
    oc = 139;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADC A,E"
       };
    (*instructions)[oc] = i;

    // ADC A,H
    oc = 140;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->HL.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADC A,H"
       };
    (*instructions)[oc] = i;

    // ADC A,L
    oc = 141;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->HL.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADC A,L"
       };
    (*instructions)[oc] = i;

    // ADC A,(HL)
    oc = 142;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, (*m)[z->getRegisters()->HL.word], r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "ADC A,(HL)"
       };
    (*instructions)[oc] = i;

    // ADC A,A
    oc = 143;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->AF.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "ADC A,A"
       };
    (*instructions)[oc] = i;

    // SUB B
    oc = 144;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SUB B"
       };
    (*instructions)[oc] = i;

    // SUB C
    oc = 145;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SUB C"
       };
    (*instructions)[oc] = i;

    // SUB D
    oc = 146;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SUB D"
       };
    (*instructions)[oc] = i;

    // SUB E
    oc = 147;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SUB E"
       };
    (*instructions)[oc] = i;

    // SUB H
    oc = 148;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->HL.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SUB H"
       };
    (*instructions)[oc] = i;

    // SUB L
    oc = 149;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->HL.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SUB L"
       };
    (*instructions)[oc] = i;

    // SUB (HL)
    oc = 150;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->HL.word]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "SUB (HL)"
       };
    (*instructions)[oc] = i;

    // SUB A
    oc = 151;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SUB A"
       };
    (*instructions)[oc] = i;

    // SBC A,B
    oc = 152;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SBC A,B"
       };
    (*instructions)[oc] = i;

    // SBC A,C
    oc = 153;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SBC A,C"
       };
    (*instructions)[oc] = i;

    // SBC A,D
    oc = 154;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SBC A,D"
       };
    (*instructions)[oc] = i;

    // SBC A,E
    oc = 155;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SBC A,E"
       };
    (*instructions)[oc] = i;

    // SBC A,H
    oc = 156;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->HL.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SBC A,H"
       };
    (*instructions)[oc] = i;

    // SBC A,L
    oc = 157;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->HL.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SBC A,L"
       };
    (*instructions)[oc] = i;

    // SBC A,(HL)
    oc = 158;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->HL.word]), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "SBC A,(HL)"
       };
    (*instructions)[oc] = i;

    // SBC A,A
    oc = 159;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "SBC A,A"
       };
    (*instructions)[oc] = i;

    // AND B
    oc = 160;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "AND B"
       };
    (*instructions)[oc] = i;

    // AND C
    oc = 161;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "AND C"
       };
    (*instructions)[oc] = i;

    // AND D
    oc = 162;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "AND D"
       };
    (*instructions)[oc] = i;

    // AND E
    oc = 163;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "AND E"
       };
    (*instructions)[oc] = i;

    // AND H
    oc = 164;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->HL.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "AND H"
       };
    (*instructions)[oc] = i;

    // AND L
    oc = 165;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->HL.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "AND L"
       };
    (*instructions)[oc] = i;

    // AND (HL)
    oc = 166;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, (*m)[z->getRegisters()->HL.word], r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "AND (HL)"
       };
    (*instructions)[oc] = i;

    // AND A
    oc = 167;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "AND A"
       };
    (*instructions)[oc] = i;

    // XOR B
    oc = 168;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "XOR B"
       };
    (*instructions)[oc] = i;

    // XOR C
    oc = 169;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "XOR C"
       };
    (*instructions)[oc] = i;

    // XOR D
    oc = 170;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "XOR D"
       };
    (*instructions)[oc] = i;

    // XOR E
    oc = 171;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "XOR E"
       };
    (*instructions)[oc] = i;

    // XOR H
    oc = 172;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->HL.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "XOR H"
       };
    (*instructions)[oc] = i;

    // XOR L
    oc = 173;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->HL.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "XOR L"
       };
    (*instructions)[oc] = i;

    // XOR (HL)
    oc = 174;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, (*m)[z->getRegisters()->HL.word], r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "XOR (HL)"
       };
    (*instructions)[oc] = i;

    // XOR A
    oc = 175;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "XOR A"
       };
    (*instructions)[oc] = i;

    // OR B
    oc = 176;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "OR B"
       };
    (*instructions)[oc] = i;

    // OR C
    oc = 177;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "OR C"
       };
    (*instructions)[oc] = i;

    // OR D
    oc = 178;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "OR D"
       };
    (*instructions)[oc] = i;

    // OR E
    oc = 179;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "OR E"
       };
    (*instructions)[oc] = i;

    // OR H
    oc = 180;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->HL.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "OR H"
       };
    (*instructions)[oc] = i;

    // OR L
    oc = 181;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->HL.bytes.low, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "OR L"
       };
    (*instructions)[oc] = i;

    // OR (HL)
    oc = 182;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, (*m)[z->getRegisters()->HL.word], r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "OR (HL)"
       };
    (*instructions)[oc] = i;

    // OR A
    oc = 183;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "OR A"
       };
    (*instructions)[oc] = i;

    // CP B
    oc = 184;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CP B"
       };
    (*instructions)[oc] = i;

    // CP C
    oc = 185;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CP C"
       };
    (*instructions)[oc] = i;

    // CP D
    oc = 186;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CP D"
       };
    (*instructions)[oc] = i;

    // CP E
    oc = 187;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CP E"
       };
    (*instructions)[oc] = i;

    // CP H
    oc = 188;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->HL.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CP H"
       };
    (*instructions)[oc] = i;

    // CP L
    oc = 189;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->HL.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CP L"
       };
    (*instructions)[oc] = i;

    // CP (HL)
    oc = 190;
    i = { 7, 7, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->HL.word]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "CP (HL)"
       };
    (*instructions)[oc] = i;

    // CP A
    oc = 191;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "CP A"
       };
    (*instructions)[oc] = i;

    // RET NZ
    oc = 192;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::NZ);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET NZ"
       };
    (*instructions)[oc] = i;

    // POP BC
    oc = 193;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "POP BC"
       };
    (*instructions)[oc] = i;

    // JP NZ,nn
    oc = 194;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.ZF))
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP NZ,nn"
       };
    (*instructions)[oc] = i;

    // JP nn
    oc = 195;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            r->PC = nn;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP nn"
       };
    (*instructions)[oc] = i;

    // CALL NZ,nn
    oc = 196;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::NZ, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL NZ,nn"
       };
    (*instructions)[oc] = i;

    // PUSH BC
    oc = 197;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->BC.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->BC.bytes.low;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "PUSH BC"
       };
    (*instructions)[oc] = i;

    // ADD A,n
    oc = 198;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, d[0], r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "ADD A,n"
       };
    (*instructions)[oc] = i;

    // RST 00
    oc = 199;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x00;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 00"
       };
    (*instructions)[oc] = i;

    // RET Z
    oc = 200;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::Z);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET Z"
       };
    (*instructions)[oc] = i;

    // RET
    oc = 201;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0 | (*m)[r->SP];
            r->SP++;
            r->PC |= ((*m)[r->SP]) << 8;
            r->SP++;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "RET"
       };
    (*instructions)[oc] = i;

    // JP Z,nn
    oc = 202;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.ZF)
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP Z,nn"
       };
    (*instructions)[oc] = i;

    // 0x00CB is prefix

    // CALL Z,nn
    oc = 204;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::Z, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL Z,nn"
       };
    (*instructions)[oc] = i;

    // CALL nn
    oc = 205;
    i = { 17, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            r->SP--;
            (*m)[r->SP] = (r->PC) >> 8;
            r->SP--;
            (*m)[r->SP] = (r->PC) & 0xFF;
            r->PC = nn;
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL nn"
       };
    (*instructions)[oc] = i;

    // ADC A,n
    oc = 206;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, d[0], r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "ADC A,n"
       };
    (*instructions)[oc] = i;

    // RST 08
    oc = 207;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x08;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 08"
       };
    (*instructions)[oc] = i;

    // RET NC
    oc = 208;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::NC);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET NC"
       };
    (*instructions)[oc] = i;

    // POP DE
    oc = 209;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "POP DE"
       };
    (*instructions)[oc] = i;

    // JP NC,nn
    oc = 210;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.CF))
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP NC,nn"
       };
    (*instructions)[oc] = i;

    // OUT (n),A
    oc = 211;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            z->getIoPorts()->writeToPort(CREATE_WORD(d[0], r->AF.bytes.high), r->AF.bytes.high);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 0, 0, 0, 0 },
        "OUT (n),A"
       };
    (*instructions)[oc] = i;

    // CALL NC,nn
    oc = 212;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::NC, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL NC,nn"
       };
    (*instructions)[oc] = i;

    // PUSH DE
    oc = 213;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->DE.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->DE.bytes.low;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "PUSH DE"
       };
    (*instructions)[oc] = i;

    // SUB n
    oc = 214;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "SUB n"
       };
    (*instructions)[oc] = i;

    // RST 10
    oc = 215;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x10;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 10"
       };
    (*instructions)[oc] = i;

    // RET C
    oc = 216;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::C);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET C"
       };
    (*instructions)[oc] = i;

    // EXX
    oc = 217;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->BC.word;
            r->BC.word = r->BCx.word;
            r->BCx.word = tmp;
            tmp = r->DE.word;
            r->DE.word = r->DEx.word;
            r->DEx.word = tmp;
            tmp = r->HL.word;
            r->HL.word = r->HLx.word;
            r->HLx.word = tmp;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "EXX"
       };
    (*instructions)[oc] = i;

    // JP C,nn
    oc = 218;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.CF)
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP C,nn"
       };
    (*instructions)[oc] = i;

    // IN A,(n)
    oc = 219;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = z->getIoPorts()->readPort(CREATE_WORD(d[0], r->AF.bytes.high));
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 0, 0, 0, 0 },
        "IN A,(n)"
       };
    (*instructions)[oc] = i;

    // CALL C,nn
    oc = 220;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::C, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL C,nn"
       };
    (*instructions)[oc] = i;

    // 0xDD is prefix

    // SBC A,n
    oc = 222;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "SBC A,n"
       };
    (*instructions)[oc] = i;

    // RST 18
    oc = 223;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x18;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 18"
       };
    (*instructions)[oc] = i;

    // RET PO
    oc = 224;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::PO);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET PO"
       };
    (*instructions)[oc] = i;

    // POP HL
    oc = 225;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "POP HL"
       };
    (*instructions)[oc] = i;

    // JP PO,nn
    oc = 226;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.PF))
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP PO,nn"
       };
    (*instructions)[oc] = i;

    // EX (SP),HL
    oc = 227;
    i = { 19, 19, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t tmp = r->HL.bytes.low;
            r->HL.bytes.low = (*m)[r->SP];
            (*m)[r->SP] = tmp;
            tmp = r->HL.bytes.high;
            r->HL.bytes.high = (*m)[(r->SP)+1];
            (*m)[(r->SP)+1] = tmp;
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 5, 0, 0 },
        "EX (SP),HL"
       };
    (*instructions)[oc] = i;

    // CALL PO,nn
    oc = 228;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::PO, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL PO,nn"
       };
    (*instructions)[oc] = i;

    // PUSH HL
    oc = 229;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->HL.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->HL.bytes.low;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "PUSH HL"
       };
    (*instructions)[oc] = i;

    // AND n
    oc = 230;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, d[0], r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "AND n"
       };
    (*instructions)[oc] = i;

    // RST 20
    oc = 231;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x20;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 20"
       };
    (*instructions)[oc] = i;

    // RET PE
    oc = 232;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::PE);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET PE"
       };
    (*instructions)[oc] = i;

    // JP,(HL)
    oc = 233;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = r->HL.word;     // wtf
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "JP,(HL)"
       };
    (*instructions)[oc] = i;

    // JP PE,nn
    oc = 234;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.PF)
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP PE,nn"
       };
    (*instructions)[oc] = i;

    // EX DE,HL
    oc = 235;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->DE.word;
            r->DE.word = r->HL.word;
            r->HL.word = tmp;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "EX DE,HL"
       };
    (*instructions)[oc] = i;

    // CALL PE,nn
    oc = 236;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::PE, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL PE,nn"
       };
    (*instructions)[oc] = i;

    // 0xED is prefix

    // XOR n
    oc = 238;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, d[0], r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "XOR n"
       };
    (*instructions)[oc] = i;

    // RST 28
    oc = 239;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x28;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 28"
       };
    (*instructions)[oc] = i;

    // RET P
    oc = 240;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::P);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET P"
       };
    (*instructions)[oc] = i;

    // POP AF
    oc = 241;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "POP AF"
       };
    (*instructions)[oc] = i;

    // JP P,nn
    oc = 242;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.SF))
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP P,nn"
       };
    (*instructions)[oc] = i;

    // DI
    oc = 243;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            z->setIFF1(false);
            z->setIFF2(false);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "DI"
       };
    (*instructions)[oc] = i;

    // CALL P,nn
    oc = 244;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::P, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL P,nn"
       };
    (*instructions)[oc] = i;

    // PUSH AF
    oc = 245;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->AF.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->AF.bytes.low.byte;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "PUSH AF"
       };
    (*instructions)[oc] = i;

    // OR n
    oc = 246;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, d[0], r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "OR n"
       };
    (*instructions)[oc] = i;

    // RST 30
    oc = 247;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x30;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 30"
       };
    (*instructions)[oc] = i;

    // RET M
    oc = 248;
    i = { 5, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::M);
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RET M"
       };
    (*instructions)[oc] = i;

    // LD SP,HL
    oc = 249;
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = r->HL.word;
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 6, 0, 0, 0, 0, 0, 0 },
        "LD SP,HL"
       };
    (*instructions)[oc] = i;

    // JP M,nn
    oc = 250;
    i = { 10, 10, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.SF)
            {
                r->PC = nn;
            }
        },
        3, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 3, 0, 0, 0, 0 },
        "JP M,nn"
       };
    (*instructions)[oc] = i;

    // EI
    oc = 251;
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            z->setIFF1(true);
            z->setIFF2(true);
        },
        1, { MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 0, 0, 0, 0, 0, 0 },
        "EI"
       };
    (*instructions)[oc] = i;

    // CALL M,nn
    oc = 252;
    i = { 10, 17, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::M, nn);
        },
        5, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 4, 3, 3, 0, 0 },
        "CALL M,nn"
       };
    (*instructions)[oc] = i;

    // 0xFD is prefix

    // CP n
    oc = 254;
    i = { 7, 7, 1, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 3, 0, 0, 0, 0, 0 },
        "CP n"
       };
    (*instructions)[oc] = i;

    // RST 38
    oc = 255;
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x38;
        },
        3, { MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 5, 3, 3, 0, 0, 0, 0 },
        "RST 38"
       };
    (*instructions)[oc] = i;

    // NOP
    oc = 256;
    i = { 8, 8, 0, INST{ ; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NOP"
    };    (*instructions)[oc] = i;

    // LD BC,nn
    oc = 257;
    i = { 14, 14, 2, INST{ z->getRegisters()->BC.word = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD BC,nn"
    };    (*instructions)[oc] = i;

    // LD (BC),A
    oc = 258;
    i = { 11, 11, 0, INST{
            (*m)[z->getRegisters()->BC.word] = z->getRegisters()->AF.bytes.high;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD (BC),A"
       };
    (*instructions)[oc] = i;

    // INC BC
    oc = 259;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC BC"
       };
    (*instructions)[oc] = i;

    // INC B
    oc = 260;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x7F) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC B"
       };
    (*instructions)[oc] = i;

    // DEC B
    oc = 261;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x80) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC B"
       };
    (*instructions)[oc] = i;

    // LD B,n
    oc = 262;
    i = { 11, 11, 1, INST{ z->getRegisters()->BC.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD B,n"
    };    (*instructions)[oc] = i;

    // RLCA
    oc = 263;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high >> 7) & 0x01);
            r->AF.bytes.high = rol<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLCA"
       };
    (*instructions)[oc] = i;

    // EX AF, AF'
    oc = 264;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->AFx.word;
            r->AFx.word = r->AF.word;
            r->AF.word = tmp;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EX AF, AF'"
       };
    (*instructions)[oc] = i;

    // ADD IX,BC
    oc = 265;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IX.word = add(r->IX.word, r->BC.word, r, ADD16);
            setUndocumentedFlags(r->IX.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IX,BC"
       };
    (*instructions)[oc] = i;

    // LD A,(BC)
    oc = 266;
    i = { 11, 11, 0, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->BC.word];
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD A,(BC)"
       };
    (*instructions)[oc] = i;

    // DEC BC
    oc = 267;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC BC"
       };
    (*instructions)[oc] = i;

    // INC C
    oc = 268;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x7F) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC C"
       };
    (*instructions)[oc] = i;

    // DEC C
    oc = 269;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x80) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC C"
       };
    (*instructions)[oc] = i;

    // LD C,n
    oc = 270;
    i = { 11, 11, 1, INST{ z->getRegisters()->BC.bytes.low = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD C,n"
    };    (*instructions)[oc] = i;

    // RRCA
    oc = 271;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high) & 0x01);
            r->AF.bytes.high = ror<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRCA"
       };
    (*instructions)[oc] = i;

    // DJNZ d
    oc = 272;
    i = { 12, 17, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            if (r->BC.bytes.high != 0)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 5, 0, 0, 0 },
        "DJNZ d"
       };
    (*instructions)[oc] = i;

    // LD DE,nn
    oc = 273;
    i = { 14, 14, 2, INST{ z->getRegisters()->DE.word = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD DE,nn"
    };    (*instructions)[oc] = i;

    // LD (DE),A
    oc = 274;
    i = { 11, 11, 0, INST{
            (*m)[z->getRegisters()->DE.word] = z->getRegisters()->AF.bytes.high;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD (DE),A"
       };
    (*instructions)[oc] = i;

    // INC DE
    oc = 275;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC DE"
       };
    (*instructions)[oc] = i;

    // INC D
    oc = 276;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x7F) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC D"
       };
    (*instructions)[oc] = i;

    // DEC D
    oc = 277;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x80) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC D"
       };
    (*instructions)[oc] = i;

    // LD D,n
    oc = 278;
    i = { 11, 11, 1, INST{ z->getRegisters()->DE.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD D,n"
    };    (*instructions)[oc] = i;

    // RLA
    oc = 279;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLA"
       };
    (*instructions)[oc] = i;

    // JR d
    oc = 280;
    i = { 16, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->PC += (int8_t) d[0];
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR d"
       };
    (*instructions)[oc] = i;

    // ADD IX,DE
    oc = 281;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IX.word = add(r->IX.word, r->DE.word, r, ADD16);
            setUndocumentedFlags(r->IX.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IX,DE"
       };
    (*instructions)[oc] = i;

    // LD A,(DE)
    oc = 282;
    i = { 11, 11, 0, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->DE.word];
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD A,(DE)"
       };
    (*instructions)[oc] = i;

    // DEC DE
    oc = 283;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC DE"
       };
    (*instructions)[oc] = i;

    // INC E
    oc = 284;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x7F) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC E"
       };
    (*instructions)[oc] = i;

    // DEC E
    oc = 285;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x80) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC E"
       };
    (*instructions)[oc] = i;

    // LD E,n
    oc = 286;
    i = { 11, 11, 1, INST{ z->getRegisters()->DE.bytes.low = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD E,n"
    };    (*instructions)[oc] = i;

    // RRA
    oc = 287;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRA"
       };
    (*instructions)[oc] = i;

    // JR NZ,d
    oc = 288;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.ZF == false)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR NZ,d"
       };
    (*instructions)[oc] = i;

    // LD IXL,nn
    oc = 289;
    i = { 14, 14, 2, INST{ z->getRegisters()->IX.word = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD IXL,nn"
    };    (*instructions)[oc] = i;

    // LD (nn),IX
    oc = 290;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->IX.bytes.low;
            (*m)[nn+1] = z->getRegisters()->IX.bytes.high;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD (nn),IX"
       };
    (*instructions)[oc] = i;

    // INC IX
    oc = 291;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IX.word = add<uint16_t>(r->IX.word, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC IX"
       };
    (*instructions)[oc] = i;

    // INC IXH
    oc = 292;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IX.bytes.high == 0x7F) ? true : false;
            r->IX.bytes.high = add<uint8_t>(r->IX.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC IXH"
       };
    (*instructions)[oc] = i;

    // DEC IXH
    oc = 293;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IX.bytes.high == 0x80) ? true : false;
            r->IX.bytes.high = add<uint8_t>(r->IX.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC IXH"
       };
    (*instructions)[oc] = i;

    // LD IXH,n
    oc = 294;
    i = { 11, 11, 1, INST{ z->getRegisters()->IX.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD IXH,n"
    };    (*instructions)[oc] = i;

    // DAA
    oc = 295;
    i = { 8, 8, 0, INST{ Z80Registers* r = z->getRegisters(); daa(r); },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DAA"
    };    (*instructions)[oc] = i;

    // JR Z,d
    oc = 296;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.ZF == true)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR Z,d"
       };
    (*instructions)[oc] = i;

    // ADD IX,IX
    oc = 297;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IX.word = add(r->IX.word, r->IX.word, r, ADD16);
            setUndocumentedFlags(r->IX.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IX,IX"
       };
    (*instructions)[oc] = i;

    // LD IX,(nn)
    oc = 298;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            uint16_t in = CREATE_WORD((*m)[nn], (*m)[nn+1]);
            z->getRegisters()->IX.word = in;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD IX,(nn)"
       };
    (*instructions)[oc] = i;

    // DEC IX
    oc = 299;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IX.word = add<uint16_t>(r->IX.word, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC IX"
       };
    (*instructions)[oc] = i;

    // INC IXL
    oc = 300;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IX.bytes.low == 0x7F) ? true : false;
            r->IX.bytes.low = add<uint8_t>(r->IX.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC IXL"
       };
    (*instructions)[oc] = i;

    // DEC IXL
    oc = 301;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IX.bytes.low == 0x80) ? true : false;
            r->IX.bytes.low = add<uint8_t>(r->IX.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC IXL"
       };
    (*instructions)[oc] = i;

    // LD IXL,n
    oc = 302;
    i = { 11, 11, 1, INST{ z->getRegisters()->IX.bytes.low = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD IXL,n"
    };    (*instructions)[oc] = i;

    // CPL
    oc = 303;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = ~(r->AF.bytes.high);
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CPL"
       };
    (*instructions)[oc] = i;

    // JR NC,d
    oc = 304;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.CF == false)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR NC,d"
       };
    (*instructions)[oc] = i;

    // LD SP,nn
    oc = 305;
    i = { 14, 14, 2, INST{ z->getRegisters()->SP = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD SP,nn"
    };    (*instructions)[oc] = i;

    // LD (nn),A
    oc = 306;
    i = { 17, 17, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->AF.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 0, 0 },
        "LD (nn),A"
       };
    (*instructions)[oc] = i;

    // INC SP
    oc = 307;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = add<uint16_t>(r->SP, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC SP"
       };
    (*instructions)[oc] = i;

    // INC (IX+d)
    oc = 308;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t byte = (*m)[r->IX.word+((int8_t)(d[0]))];
            r->AF.bytes.low.PF = (byte == 0x7F) ? true : false;
            byte = add<uint8_t>(byte, 1, r, INC8);
            (*m)[r->IX.word+((int8_t)(d[0]))] = byte;
            r->AF.bytes.low.NF = false;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "INC (IX+d)"
       };
    (*instructions)[oc] = i;

    // DEC (IX+d)
    oc = 309;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t byte = (*m)[r->IX.word+((int8_t)(d[0]))];
            r->AF.bytes.low.PF = (byte == 0x80) ? true : false;
            byte = add<uint8_t>(byte, -1, r, DEC8);
            (*m)[r->IX.word+((int8_t)(d[0]))] = byte;
            r->AF.bytes.low.NF = true;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "DEC (IX+d)"
       };
    (*instructions)[oc] = i;

    // LD (IX+d),n
    oc = 310;
    i = { 23, 23, 2, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = d[1];
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "LD (IX+d),n"
       };
    (*instructions)[oc] = i;

    // SCF
    oc = 311;
    i = { 8, 8, 0, INST{
            z->getRegisters()->AF.bytes.low.CF = true;
            z->getRegisters()->AF.bytes.low.NF = false;
            z->getRegisters()->AF.bytes.low.HF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SCF"
       };
    (*instructions)[oc] = i;

    // JR C,d
    oc = 312;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.CF == true)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR C,d"
       };
    (*instructions)[oc] = i;

    // ADD IX,SP
    oc = 313;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IX.word = add(r->IX.word, r->SP, r, ADD16);
            setUndocumentedFlags(r->IX.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IX,SP"
       };
    (*instructions)[oc] = i;

    // LD A,(nn)
    oc = 314;
    i = { 17, 17, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            z->getRegisters()->AF.bytes.high = (*m)[nn];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 0, 0 },
        "LD A,(nn)"
       };
    (*instructions)[oc] = i;

    // DEC SP
    oc = 315;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = add<uint16_t>(r->SP, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC SP"
       };
    (*instructions)[oc] = i;

    // INC A
    oc = 316;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->AF.bytes.high == 0x7F) ? true : false;
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC A"
       };
    (*instructions)[oc] = i;

    // DEC A
    oc = 317;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->AF.bytes.high == 0x80) ? true : false;
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC A"
       };
    (*instructions)[oc] = i;

    // LD A,n
    oc = 318;
    i = { 11, 11, 1, INST{ z->getRegisters()->AF.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD A,n"
    };    (*instructions)[oc] = i;

    // CCF
    oc = 319;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            bool prevCarry = r->AF.bytes.low.CF;
            r->AF.bytes.low.CF = (r->AF.bytes.low.CF) ? false : true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = prevCarry;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CCF"
       };
    (*instructions)[oc] = i;

    // LD B,B
    oc = 320;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,B"
   };    (*instructions)[oc] = i;

    // LD B,C
    oc = 321;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,C"
    };    (*instructions)[oc] = i;

    // LD B,D
    oc = 322;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,D"
    };    (*instructions)[oc] = i;

    // LD B,E
    oc = 323;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,E"
    };    (*instructions)[oc] = i;

    // LD B,IXH
    oc = 324;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->IX.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,IXH"
    };    (*instructions)[oc] = i;

    // LD B,IXL
    oc = 325;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->IX.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,IXL"
    };    (*instructions)[oc] = i;

    // LD B,(IX+d)
    oc = 326;
    i = { 19, 19, 1, INST{
            z->getRegisters()->BC.bytes.high = (*m)[z->getRegisters()->IX.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD B,(IX+d)"
       };
    (*instructions)[oc] = i;

    // LD B,A
    oc = 327;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,A"
    };    (*instructions)[oc] = i;

    // LD C,B
    oc = 328;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,B"
    };    (*instructions)[oc] = i;

    // LD C,C
    oc = 329;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,C"
    };    (*instructions)[oc] = i;

    // LD C,D
    oc = 330;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,D"
    };    (*instructions)[oc] = i;

    // LD C,E
    oc = 331;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,E"
    };    (*instructions)[oc] = i;

    // LD C,IXH
    oc = 332;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->IX.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,IXH"
    };    (*instructions)[oc] = i;

    // LD C,IXL
    oc = 333;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->IX.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,IXL"
    };    (*instructions)[oc] = i;

    // LD C,(IX+d)
    oc = 334;
    i = { 19, 19, 1, INST{
            z->getRegisters()->BC.bytes.low = (*m)[z->getRegisters()->IX.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD C,(IX+d)"
       };
    (*instructions)[oc] = i;

    // LD C,A
    oc = 335;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,A"
    };    (*instructions)[oc] = i;

    // LD D,B
    oc = 336;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,B"
    };    (*instructions)[oc] = i;

    // LD D,C
    oc = 337;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,C"
    };    (*instructions)[oc] = i;

    // LD D,D
    oc = 338;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,D"
    };    (*instructions)[oc] = i;

    // LD D,E
    oc = 339;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,E"
    };    (*instructions)[oc] = i;

    // LD D,IXH
    oc = 340;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->IX.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,IXH"
    };    (*instructions)[oc] = i;

    // LD D,IXL
    oc = 341;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->IX.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,IXL"
    };    (*instructions)[oc] = i;

    // LD D,(IX+d)
    oc = 342;
    i = { 19, 19, 1, INST{
            z->getRegisters()->DE.bytes.high = (*m)[z->getRegisters()->IX.word+((int8_t)(d[0]))];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD D,(IX+d)"
       };
    (*instructions)[oc] = i;

    // LD D,A
    oc = 343;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,A"
    };    (*instructions)[oc] = i;

    // LD E,B
    oc = 344;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,B"
    };    (*instructions)[oc] = i;

    // LD E,C
    oc = 345;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,C"
    };    (*instructions)[oc] = i;

    // LD E,D
    oc = 346;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,D"
    };    (*instructions)[oc] = i;

    // LD E,E
    oc = 347;
    i = { 8, 8, 0, INST{; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,E"
    };    (*instructions)[oc] = i;

    // LD E,IXH
    oc = 348;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->IX.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,IXH"
    };    (*instructions)[oc] = i;

    // LD E,IXL
    oc = 349;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->IX.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,IXL"
    };    (*instructions)[oc] = i;

    // LD E,(IX+d)
    oc = 350;
    i = { 19, 19, 1, INST{
            z->getRegisters()->DE.bytes.low = (*m)[z->getRegisters()->IX.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD E,(IX+d)"
       };
    (*instructions)[oc] = i;

    // LD E,A
    oc = 351;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,A"
    };    (*instructions)[oc] = i;

    // LD IXH,B
    oc = 352;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.high = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXH,B"
    };    (*instructions)[oc] = i;

    // LD IXH,C
    oc = 353;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXH,C"
    };    (*instructions)[oc] = i;

    // LD IXH,D
    oc = 354;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.high = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXH,D"
    };    (*instructions)[oc] = i;

    // LD IXH,E
    oc = 355;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXH,E"
    };    (*instructions)[oc] = i;

    // LD IXH,IXH
    oc = 356;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXH,IXH"
    };    (*instructions)[oc] = i;

    // LD IXH,IXL
    oc = 357;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.high = z->getRegisters()->IX.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXH,IXL"
    };    (*instructions)[oc] = i;

    // LD H,(IX+d)
    oc = 358;
    i = { 19, 19, 1, INST{
            z->getRegisters()->HL.bytes.high = (*m)[z->getRegisters()->IX.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD H,(IX+d)"
       };
    (*instructions)[oc] = i;

    // LD IXH,A
    oc = 359;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.high = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXH,A"
    };    (*instructions)[oc] = i;

    // LD IXL,B
    oc = 360;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.low = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXL,B"
    };    (*instructions)[oc] = i;

    // LD IXL,C
    oc = 361;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.low = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXL,C"
    };    (*instructions)[oc] = i;

    // LD IXL,D
    oc = 362;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.low = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXL,D"
    };    (*instructions)[oc] = i;

    // LD IXL,E
    oc = 363;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.low = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXL,E"
    };    (*instructions)[oc] = i;

    // LD IXL,IXH
    oc = 364;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.low = z->getRegisters()->IX.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXL,IXH"
    };    (*instructions)[oc] = i;

    // LD IXL,IXL
    oc = 365;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXL,IXL"
    };    (*instructions)[oc] = i;

    // LD L,(IX+d)
    oc = 366;
    i = { 19, 19, 1, INST{
            z->getRegisters()->HL.bytes.low = (*m)[z->getRegisters()->IX.word+((int8_t)(d[0]))];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD L,(IX+d)"
       };
    (*instructions)[oc] = i;

    // LD IXL,A
    oc = 367;
    i = { 8, 8, 0, INST{ z->getRegisters()->IX.bytes.low = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IXL,A"
    };    (*instructions)[oc] = i;

    // LD (IX+d),B
    oc = 368;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = z->getRegisters()->BC.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IX+d),B"
       };
    (*instructions)[oc] = i;

    // LD (IX+d),C
    oc = 369;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = z->getRegisters()->BC.bytes.low;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IX+d),C"
       };
    (*instructions)[oc] = i;

    // LD (IX+d),D
    oc = 370;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = z->getRegisters()->DE.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IX+d),D"
       };
    (*instructions)[oc] = i;

    // LD (IX+d),E
    oc = 371;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = z->getRegisters()->DE.bytes.low;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IX+d),E"
       };
    (*instructions)[oc] = i;

    // LD (IX+d),H
    oc = 372;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = z->getRegisters()->HL.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IX+d),H"
       };
    (*instructions)[oc] = i;

    // LD (IX+d),L
    oc = 373;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = z->getRegisters()->HL.bytes.low;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IX+d),L"
       };
    (*instructions)[oc] = i;

    // HALT
    oc = 374;
    i = { 8, 8, 0, INST{
            z->halt();
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "HALT"
       };
    (*instructions)[oc] = i;

    // LD (IX+d),A
    oc = 375;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IX.word+((int8_t)d[0])] = z->getRegisters()->AF.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IX+d),A"
       };
    (*instructions)[oc] = i;

    // LD A,B
    oc = 376;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,B"
    };    (*instructions)[oc] = i;

    // LD A,C
    oc = 377;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,C"
    };    (*instructions)[oc] = i;

    // LD A,D
    oc = 378;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,D"
    };    (*instructions)[oc] = i;

    // LD A,E
    oc = 379;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,E"
    };    (*instructions)[oc] = i;

    // LD A,IXH
    oc = 380;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->IX.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,IXH"
    };    (*instructions)[oc] = i;

    // LD A,IXL
    oc = 381;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->IX.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,IXL"
    };    (*instructions)[oc] = i;

    // LD A,(IX+d)
    oc = 382;
    i = { 19, 19, 1, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->IX.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD A,(IX+d)"
       };
    (*instructions)[oc] = i;

    // LD A,A
    oc = 383;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,A"
    };    (*instructions)[oc] = i;

    // ADD A,B
    oc = 384;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,B"
       };
    (*instructions)[oc] = i;

    // ADD A,C
    oc = 385;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,C"
       };
    (*instructions)[oc] = i;

    // ADD A,D
    oc = 386;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,D"
       };
    (*instructions)[oc] = i;

    // ADD A,E
    oc = 387;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,E"
       };
    (*instructions)[oc] = i;

    // ADD A,IXH
    oc = 388;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IX.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,IXH"
       };
    (*instructions)[oc] = i;

    // ADD A,IXL
    oc = 389;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IX.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,IXL"
       };
    (*instructions)[oc] = i;

    // ADD A,(IX+d)
    oc = 390;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, (*m)[z->getRegisters()->IX.word+((int8_t)d[0])], r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "ADD A,(IX+d)"
       };
    (*instructions)[oc] = i;

    // ADD A,A
    oc = 391;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->AF.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,A"
       };
    (*instructions)[oc] = i;

    // ADC A,B
    oc = 392;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,B"
       };
    (*instructions)[oc] = i;

    // ADC A,C
    oc = 393;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,C"
       };
    (*instructions)[oc] = i;

    // ADC A,D
    oc = 394;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,D"
       };
    (*instructions)[oc] = i;

    // ADC A,E
    oc = 395;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,E"
       };
    (*instructions)[oc] = i;

    // ADC A,IXH
    oc = 396;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IX.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,IXH"
       };
    (*instructions)[oc] = i;

    // ADC A,IXL
    oc = 397;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IX.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,IXL"
       };
    (*instructions)[oc] = i;

    // ADC A,(IX+d)
    oc = 398;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, (*m)[z->getRegisters()->IX.word+((int8_t)d[0])], r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "ADC A,(IX+d)"
       };
    (*instructions)[oc] = i;

    // ADC A,A
    oc = 399;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->AF.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,A"
       };
    (*instructions)[oc] = i;

    // SUB B
    oc = 400;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB B"
       };
    (*instructions)[oc] = i;

    // SUB C
    oc = 401;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB C"
       };
    (*instructions)[oc] = i;

    // SUB D
    oc = 402;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB D"
       };
    (*instructions)[oc] = i;

    // SUB E
    oc = 403;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB E"
       };
    (*instructions)[oc] = i;

    // SUB IXH
    oc = 404;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IX.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB IXH"
       };
    (*instructions)[oc] = i;

    // SUB IXL
    oc = 405;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IX.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB IXL"
       };
    (*instructions)[oc] = i;

    // SUB (IX+d)
    oc = 406;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->IX.word+((int8_t)d[0])]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "SUB (IX+d)"
       };
    (*instructions)[oc] = i;

    // SUB A
    oc = 407;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB A"
       };
    (*instructions)[oc] = i;

    // SBC A,B
    oc = 408;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,B"
       };
    (*instructions)[oc] = i;

    // SBC A,C
    oc = 409;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,C"
       };
    (*instructions)[oc] = i;

    // SBC A,D
    oc = 410;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,D"
       };
    (*instructions)[oc] = i;

    // SBC A,E
    oc = 411;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,E"
       };
    (*instructions)[oc] = i;

    // SBC A,IXH
    oc = 412;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IX.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,IXH"
       };
    (*instructions)[oc] = i;

    // SBC A,IXL
    oc = 413;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IX.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,IXL"
       };
    (*instructions)[oc] = i;

    // SBC A,(IX+d)
    oc = 414;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->IX.word+((int8_t)d[0])]), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "SBC A,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SBC A,A
    oc = 415;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,A"
       };
    (*instructions)[oc] = i;

    // AND B
    oc = 416;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND B"
       };
    (*instructions)[oc] = i;

    // AND C
    oc = 417;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND C"
       };
    (*instructions)[oc] = i;

    // AND D
    oc = 418;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND D"
       };
    (*instructions)[oc] = i;

    // AND E
    oc = 419;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND E"
       };
    (*instructions)[oc] = i;

    // AND IXH
    oc = 420;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->IX.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND IXH"
       };
    (*instructions)[oc] = i;

    // AND IXL
    oc = 421;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->IX.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND IXL"
       };
    (*instructions)[oc] = i;

    // AND (IX+d)
    oc = 422;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, (*m)[z->getRegisters()->IX.word+((int8_t)d[0])], r);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "AND (IX+d)"
       };
    (*instructions)[oc] = i;

    // AND A
    oc = 423;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND A"
       };
    (*instructions)[oc] = i;

    // XOR B
    oc = 424;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR B"
       };
    (*instructions)[oc] = i;

    // XOR C
    oc = 425;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR C"
       };
    (*instructions)[oc] = i;

    // XOR D
    oc = 426;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR D"
       };
    (*instructions)[oc] = i;

    // XOR E
    oc = 427;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR E"
       };
    (*instructions)[oc] = i;

    // XOR IXH
    oc = 428;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->IX.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR IXH"
       };
    (*instructions)[oc] = i;

    // XOR IXL
    oc = 429;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->IX.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR IXL"
       };
    (*instructions)[oc] = i;

    // XOR (IX+d)
    oc = 430;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, (*m)[z->getRegisters()->IX.word+((int8_t)d[0])], r);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "XOR (IX+d)"
       };
    (*instructions)[oc] = i;

    // XOR A
    oc = 431;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR A"
       };
    (*instructions)[oc] = i;

    // OR B
    oc = 432;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR B"
       };
    (*instructions)[oc] = i;

    // OR C
    oc = 433;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR C"
       };
    (*instructions)[oc] = i;

    // OR D
    oc = 434;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR D"
       };
    (*instructions)[oc] = i;

    // OR E
    oc = 435;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR E"
       };
    (*instructions)[oc] = i;

    // OR IXH
    oc = 436;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->IX.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR IXH"
       };
    (*instructions)[oc] = i;

    // OR IXL
    oc = 437;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->IX.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR IXL"
       };
    (*instructions)[oc] = i;

    // OR (IX+d)
    oc = 438;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, (*m)[z->getRegisters()->IX.word+((int8_t)d[0])], r);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "OR (IX+d)"
       };
    (*instructions)[oc] = i;

    // OR A
    oc = 439;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR A"
       };
    (*instructions)[oc] = i;

    // CP B
    oc = 440;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP B"
       };
    (*instructions)[oc] = i;

    // CP C
    oc = 441;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP C"
       };
    (*instructions)[oc] = i;

    // CP D
    oc = 442;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP D"
       };
    (*instructions)[oc] = i;

    // CP E
    oc = 443;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP E"
       };
    (*instructions)[oc] = i;

    // CP IXH
    oc = 444;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->IX.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP IXH"
       };
    (*instructions)[oc] = i;

    // CP IXL
    oc = 445;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->IX.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP IXL"
       };
    (*instructions)[oc] = i;

    // CP (IX+d)
    oc = 446;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->IX.word+((int8_t)d[0])]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "CP (IX+d)"
       };
    (*instructions)[oc] = i;

    // CP A
    oc = 447;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP A"
       };
    (*instructions)[oc] = i;

    // RET NZ
    oc = 448;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::NZ);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET NZ"
       };
    (*instructions)[oc] = i;

    // POP BC
    oc = 449;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP BC"
       };
    (*instructions)[oc] = i;

    // JP NZ,nn
    oc = 450;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.ZF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP NZ,nn"
       };
    (*instructions)[oc] = i;

    // JP nn
    oc = 451;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            r->PC = nn;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP nn"
       };
    (*instructions)[oc] = i;

    // CALL NZ,nn
    oc = 452;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::NZ, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL NZ,nn"
       };
    (*instructions)[oc] = i;

    // PUSH BC
    oc = 453;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->BC.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->BC.bytes.low;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH BC"
       };
    (*instructions)[oc] = i;

    // ADD A,n
    oc = 454;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, d[0], r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADD A,n"
       };
    (*instructions)[oc] = i;

    // RST 00
    oc = 455;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x00;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 00"
       };
    (*instructions)[oc] = i;

    // RET Z
    oc = 456;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::Z);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET Z"
       };
    (*instructions)[oc] = i;

    // RET
    oc = 457;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0 | (*m)[r->SP];
            r->SP++;
            r->PC |= ((*m)[r->SP]) << 8;
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RET"
       };
    (*instructions)[oc] = i;

    // JP Z,nn
    oc = 458;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.ZF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP Z,nn"
       };
    (*instructions)[oc] = i;

    // 0x00CB is prefix

    // CALL Z,nn
    oc = 460;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::Z, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL Z,nn"
       };
    (*instructions)[oc] = i;

    // CALL nn
    oc = 461;
    i = { 21, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            r->SP--;
            (*m)[r->SP] = (r->PC) >> 8;
            r->SP--;
            (*m)[r->SP] = (r->PC) & 0xFF;
            r->PC = nn;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL nn"
       };
    (*instructions)[oc] = i;

    // ADC A,n
    oc = 462;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, d[0], r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADC A,n"
       };
    (*instructions)[oc] = i;

    // RST 08
    oc = 463;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x08;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 08"
       };
    (*instructions)[oc] = i;

    // RET NC
    oc = 464;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::NC);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET NC"
       };
    (*instructions)[oc] = i;

    // POP DE
    oc = 465;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP DE"
       };
    (*instructions)[oc] = i;

    // JP NC,nn
    oc = 466;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.CF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP NC,nn"
       };
    (*instructions)[oc] = i;

    // OUT (n),A
    oc = 467;
    i = { 15, 15, 1, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(d[0], r->AF.bytes.high)] = r->AF.bytes.high;
            z->getIoPorts()->writeToPort(CREATE_WORD(d[0], r->AF.bytes.high), r->AF.bytes.high);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 0, 0, 0 },
        "OUT (n),A"
       };
    (*instructions)[oc] = i;

    // CALL NC,nn
    oc = 468;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::NC, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL NC,nn"
       };
    (*instructions)[oc] = i;

    // PUSH DE
    oc = 469;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->DE.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->DE.bytes.low;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH DE"
       };
    (*instructions)[oc] = i;

    // SUB n
    oc = 470;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "SUB n"
       };
    (*instructions)[oc] = i;

    // RST 10
    oc = 471;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x10;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 10"
       };
    (*instructions)[oc] = i;

    // RET C
    oc = 472;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::C);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET C"
       };
    (*instructions)[oc] = i;

    // EXX
    oc = 473;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->BC.word;
            r->BC.word = r->BCx.word;
            r->BCx.word = tmp;
            tmp = r->DE.word;
            r->DE.word = r->DEx.word;
            r->DEx.word = tmp;
            tmp = r->HL.word;
            r->HL.word = r->HLx.word;
            r->HLx.word = tmp;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EXX"
       };
    (*instructions)[oc] = i;

    // JP C,nn
    oc = 474;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.CF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP C,nn"
       };
    (*instructions)[oc] = i;

    // IN A,(n)
    oc = 475;
    i = { 15, 15, 1, INST{
            Z80Registers* r = z->getRegisters();
            // r->AF.bytes.high = (*(z->getIoPorts()))[CREATE_WORD(d[0], r->AF.bytes.high)];
            r->AF.bytes.high = z->getIoPorts()->readPort(CREATE_WORD(d[0], r->AF.bytes.high));
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 0, 0, 0 },
        "IN A,(n)"
       };
    (*instructions)[oc] = i;

    // CALL C,nn
    oc = 476;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::C, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL C,nn"
       };
    (*instructions)[oc] = i;

    // 0xDD is prefix

    // SBC A,n
    oc = 478;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "SBC A,n"
       };
    (*instructions)[oc] = i;

    // RST 18
    oc = 479;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x18;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 18"
       };
    (*instructions)[oc] = i;

    // RET PO
    oc = 480;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::PO);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET PO"
       };
    (*instructions)[oc] = i;

    // POP IX
    oc = 481;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IX.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP IX"
       };
    (*instructions)[oc] = i;

    // JP PO,nn
    oc = 482;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.PF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP PO,nn"
       };
    (*instructions)[oc] = i;

    // EX (SP),IX
    oc = 483;
    i = { 23, 23, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t tmp = r->IX.bytes.low;
            r->IX.bytes.low = (*m)[r->SP];
            (*m)[r->SP] = tmp;
            tmp = r->IX.bytes.high;
            r->IX.bytes.high = (*m)[(r->SP)+1];
            (*m)[(r->SP)+1] = tmp;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 5, 0 },
        "EX (SP),IX"
       };
    (*instructions)[oc] = i;

    // CALL PO,nn
    oc = 484;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::PO, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL PO,nn"
       };
    (*instructions)[oc] = i;

    // PUSH IX
    oc = 485;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->IX.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->IX.bytes.low;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH IX"
       };
    (*instructions)[oc] = i;

    // AND n
    oc = 486;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, d[0], r);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "AND n"
       };
    (*instructions)[oc] = i;

    // RST 20
    oc = 487;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x20;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 20"
       };
    (*instructions)[oc] = i;

    // RET PE
    oc = 488;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::PE);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET PE"
       };
    (*instructions)[oc] = i;

    // JP,(IX)
    oc = 489;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->PC = (*m)[r->IX.word];
            r->PC = r->IX.word;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "JP,(IX)"
       };
    (*instructions)[oc] = i;

    // JP PE,nn
    oc = 490;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.PF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP PE,nn"
       };
    (*instructions)[oc] = i;

    // EX DE,HL
    oc = 491;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->DE.word;
            r->DE.word = r->HL.word;
            r->HL.word = tmp;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EX DE,HL"
       };
    (*instructions)[oc] = i;

    // CALL PE,nn
    oc = 492;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::PE, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL PE,nn"
       };
    (*instructions)[oc] = i;

    // 0xED is prefix

    // XOR n
    oc = 494;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, d[0], r);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "XOR n"
       };
    (*instructions)[oc] = i;

    // RST 28
    oc = 495;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x28;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 28"
       };
    (*instructions)[oc] = i;

    // RET P
    oc = 496;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::P);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET P"
       };
    (*instructions)[oc] = i;

    // POP AF
    oc = 497;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP AF"
       };
    (*instructions)[oc] = i;

    // JP P,nn
    oc = 498;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.SF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP P,nn"
       };
    (*instructions)[oc] = i;

    // DI
    oc = 499;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            z->setIFF1(false);
            z->setIFF2(false);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DI"
       };
    (*instructions)[oc] = i;

    // CALL P,nn
    oc = 500;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::P, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL P,nn"
       };
    (*instructions)[oc] = i;

    // PUSH AF
    oc = 501;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->AF.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->AF.bytes.low.byte;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH AF"
       };
    (*instructions)[oc] = i;

    // OR n
    oc = 502;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, d[0], r);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "OR n"
       };
    (*instructions)[oc] = i;

    // RST 30
    oc = 503;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x30;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 30"
       };
    (*instructions)[oc] = i;

    // RET M
    oc = 504;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::M);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET M"
       };
    (*instructions)[oc] = i;

    // LD SP,IX
    oc = 505;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = r->IX.word;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "LD SP,IX"
       };
    (*instructions)[oc] = i;

    // JP M,nn
    oc = 506;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.SF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP M,nn"
       };
    (*instructions)[oc] = i;

    // EI
    oc = 507;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            z->setIFF1(true);
            z->setIFF2(true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EI"
       };
    (*instructions)[oc] = i;

    // CALL M,nn
    oc = 508;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::M, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL M,nn"
       };
    (*instructions)[oc] = i;

    // 0xFD is prefix

    // CP n
    oc = 510;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "CP n"
       };
    (*instructions)[oc] = i;

    // RST 38
    oc = 511;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x38;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 38"
       };
    (*instructions)[oc] = i;

    // NOP
    oc = 512;
    i = { 8, 8, 0, INST{ ; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NOP"
    };    (*instructions)[oc] = i;

    // LD BC,nn
    oc = 513;
    i = { 14, 14, 2, INST{ z->getRegisters()->BC.word = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD BC,nn"
    };    (*instructions)[oc] = i;

    // LD (BC),A
    oc = 514;
    i = { 11, 11, 0, INST{
            (*m)[z->getRegisters()->BC.word] = z->getRegisters()->AF.bytes.high;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD (BC),A"
       };
    (*instructions)[oc] = i;

    // INC BC
    oc = 515;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC BC"
       };
    (*instructions)[oc] = i;

    // INC B
    oc = 516;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x7F) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC B"
       };
    (*instructions)[oc] = i;

    // DEC B
    oc = 517;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.high == 0x80) ? true : false;
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC B"
       };
    (*instructions)[oc] = i;

    // LD B,n
    oc = 518;
    i = { 11, 11, 1, INST{ z->getRegisters()->BC.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD B,n"
    };    (*instructions)[oc] = i;

    // RLCA
    oc = 519;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high >> 7) & 0x01);
            r->AF.bytes.high = rol<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLCA"
       };
    (*instructions)[oc] = i;

    // EX AF, AF'
    oc = 520;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->AFx.word;
            r->AFx.word = r->AF.word;
            r->AF.word = tmp;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EX AF, AF'"
       };
    (*instructions)[oc] = i;

    // ADD IY,BC
    oc = 521;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IY.word = add(r->IY.word, r->BC.word, r, ADD16);
            setUndocumentedFlags(r->IY.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IY,BC"
       };
    (*instructions)[oc] = i;

    // LD A,(BC)
    oc = 522;
    i = { 11, 11, 0, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->BC.word];
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD A,(BC)"
       };
    (*instructions)[oc] = i;

    // DEC BC
    oc = 523;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC BC"
       };
    (*instructions)[oc] = i;

    // INC C
    oc = 524;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x7F) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC C"
       };
    (*instructions)[oc] = i;

    // DEC C
    oc = 525;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->BC.bytes.low == 0x80) ? true : false;
            r->BC.bytes.low = add<uint8_t>(r->BC.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC C"
       };
    (*instructions)[oc] = i;

    // LD C,n
    oc = 526;
    i = { 11, 11, 1, INST{ z->getRegisters()->BC.bytes.low = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD C,n"
    };    (*instructions)[oc] = i;

    // RRCA
    oc = 527;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high) & 0x01);
            r->AF.bytes.high = ror<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRCA"
       };
    (*instructions)[oc] = i;

    // DJNZ d
    oc = 528;
    i = { 12, 17, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            if (r->BC.bytes.high != 0)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 5, 0, 0, 0 },
        "DJNZ d"
       };
    (*instructions)[oc] = i;

    // LD DE,nn
    oc = 529;
    i = { 14, 14, 2, INST{ z->getRegisters()->DE.word = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD DE,nn"
    };    (*instructions)[oc] = i;

    // LD (DE),A
    oc = 530;
    i = { 11, 11, 0, INST{
            (*m)[z->getRegisters()->DE.word] = z->getRegisters()->AF.bytes.high;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD (DE),A"
       };
    (*instructions)[oc] = i;

    // INC DE
    oc = 531;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC DE"
       };
    (*instructions)[oc] = i;

    // INC D
    oc = 532;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x7F) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC D"
       };
    (*instructions)[oc] = i;

    // DEC D
    oc = 533;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x80) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC D"
       };
    (*instructions)[oc] = i;

    // LD D,n
    oc = 534;
    i = { 11, 11, 1, INST{ z->getRegisters()->DE.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD D,n"
    };    (*instructions)[oc] = i;

    // RLA
    oc = 535;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLA"
       };
    (*instructions)[oc] = i;

    // JR d
    oc = 536;
    i = { 0, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->PC += (int8_t) d[0];
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR d"
       };
    (*instructions)[oc] = i;

    // ADD IY,DE
    oc = 537;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IY.word = add(r->IY.word, r->DE.word, r, ADD16);
            setUndocumentedFlags(r->IY.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IY,DE"
       };
    (*instructions)[oc] = i;

    // LD A,(DE)
    oc = 538;
    i = { 11, 11, 0, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->DE.word];
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD A,(DE)"
       };
    (*instructions)[oc] = i;

    // DEC DE
    oc = 539;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC DE"
       };
    (*instructions)[oc] = i;

    // INC E
    oc = 540;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x7F) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC E"
       };
    (*instructions)[oc] = i;

    // DEC E
    oc = 541;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x80) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC E"
       };
    (*instructions)[oc] = i;

    // LD E,n
    oc = 542;
    i = { 11, 11, 1, INST{ z->getRegisters()->DE.bytes.low = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD E,n"
    };    (*instructions)[oc] = i;

    // RRA
    oc = 543;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRA"
       };
    (*instructions)[oc] = i;

    // JR NZ,d
    oc = 544;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.ZF == false)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR NZ,d"
       };
    (*instructions)[oc] = i;

    // LD IYL,nn
    oc = 545;
    i = { 14, 14, 2, INST{ z->getRegisters()->IY.word = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD IYL,nn"
    };    (*instructions)[oc] = i;

    // LD (nn),IY
    oc = 546;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->IY.bytes.low;
            (*m)[nn+1] = z->getRegisters()->IY.bytes.high;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD (nn),IY"
       };
    (*instructions)[oc] = i;

    // INC IY
    oc = 547;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IY.word = add<uint16_t>(r->IY.word, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC IY"
       };
    (*instructions)[oc] = i;

    // INC IYH
    oc = 548;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IY.bytes.high == 0x7F) ? true : false;
            r->IY.bytes.high = add<uint8_t>(r->IY.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC IYH"
       };
    (*instructions)[oc] = i;

    // DEC IYH
    oc = 549;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IY.bytes.high == 0x80) ? true : false;
            r->IY.bytes.high = add<uint8_t>(r->IY.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC IYH"
       };
    (*instructions)[oc] = i;

    // LD IYH,n
    oc = 550;
    i = { 11, 11, 1, INST{ z->getRegisters()->IY.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD IYH,n"
    };    (*instructions)[oc] = i;

    // DAA
    oc = 551;
    i = { 8, 8, 0, INST{ Z80Registers* r = z->getRegisters(); daa(r); },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DAA"
    };    (*instructions)[oc] = i;

    // JR Z,d
    oc = 552;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.ZF == true)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR Z,d"
       };
    (*instructions)[oc] = i;

    // ADD IY,IY
    oc = 553;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IY.word = add(r->IY.word, r->IY.word, r, ADD16);
            setUndocumentedFlags(r->IY.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IY,IY"
       };
    (*instructions)[oc] = i;

    // LD IY,(nn)
    oc = 554;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            uint16_t in = CREATE_WORD((*m)[nn], (*m)[nn+1]);
            z->getRegisters()->IY.word = in;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD IY,(nn)"
       };
    (*instructions)[oc] = i;

    // DEC IY
    oc = 555;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IY.word = add<uint16_t>(r->IY.word, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC IY"
       };
    (*instructions)[oc] = i;

    // INC IYL
    oc = 556;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IY.bytes.low == 0x7F) ? true : false;
            r->IY.bytes.low = add<uint8_t>(r->IY.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC IYL"
       };
    (*instructions)[oc] = i;

    // DEC IYL
    oc = 557;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->IY.bytes.low == 0x80) ? true : false;
            r->IY.bytes.low = add<uint8_t>(r->IY.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC IYL"
       };
    (*instructions)[oc] = i;

    // LD IYL,n
    oc = 558;
    i = { 11, 11, 1, INST{ z->getRegisters()->IY.bytes.low = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD IYL,n"
    };    (*instructions)[oc] = i;

    // CPL
    oc = 559;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = ~(r->AF.bytes.high);
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CPL"
       };
    (*instructions)[oc] = i;

    // JR NC,d
    oc = 560;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.CF == false)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR NC,d"
       };
    (*instructions)[oc] = i;

    // LD SP,nn
    oc = 561;
    i = { 14, 14, 2, INST{ z->getRegisters()->SP = CREATE_WORD(d[0], d[1]); },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "LD SP,nn"
    };    (*instructions)[oc] = i;

    // LD (nn),A
    oc = 562;
    i = { 17, 17, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->AF.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 0, 0 },
        "LD (nn),A"
       };
    (*instructions)[oc] = i;

    // INC SP
    oc = 563;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = add<uint16_t>(r->SP, 1, r, INC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "INC SP"
       };
    (*instructions)[oc] = i;

    // INC (IY+d)
    oc = 564;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t byte = (*m)[r->IY.word+((int8_t)(d[0]))];
            r->AF.bytes.low.PF = (byte == 0x7F) ? true : false;
            byte = add<uint8_t>(byte, 1, r, INC8);
            (*m)[r->IY.word+((int8_t)(d[0]))] = byte;
            r->AF.bytes.low.NF = false;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "INC (IY+d)"
       };
    (*instructions)[oc] = i;

    // DEC (IY+d)
    oc = 565;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t byte = (*m)[r->IY.word+((int8_t)(d[0]))];
            r->AF.bytes.low.PF = (byte == 0x80) ? true : false;
            byte = add<uint8_t>(byte, -1, r, DEC8);
            (*m)[r->IY.word+((int8_t)(d[0]))] = byte;
            r->AF.bytes.low.NF = true;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "DEC (IY+d)"
       };
    (*instructions)[oc] = i;

    // LD (IY+d),n
    oc = 566;
    i = { 23, 23, 2, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = d[1];
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "LD (IY+d),n"
       };
    (*instructions)[oc] = i;

    // SCF
    oc = 567;
    i = { 8, 8, 0, INST{
            z->getRegisters()->AF.bytes.low.CF = true;
            z->getRegisters()->AF.bytes.low.NF = false;
            z->getRegisters()->AF.bytes.low.HF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SCF"
       };
    (*instructions)[oc] = i;

    // JR C,d
    oc = 568;
    i = { 11, 16, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.CF == true)
            {
                r->PC += (int8_t) d[0];
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "JR C,d"
       };
    (*instructions)[oc] = i;

    // ADD IY,SP
    oc = 569;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IY.word = add(r->IY.word, r->SP, r, ADD16);
            setUndocumentedFlags(r->IY.word, r);
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADD IY,SP"
       };
    (*instructions)[oc] = i;

    // LD A,(nn)
    oc = 570;
    i = { 17, 17, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            z->getRegisters()->AF.bytes.high = (*m)[nn];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 0, 0 },
        "LD A,(nn)"
       };
    (*instructions)[oc] = i;

    // DEC SP
    oc = 571;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = add<uint16_t>(r->SP, -1, r, DEC16);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "DEC SP"
       };
    (*instructions)[oc] = i;

    // INC A
    oc = 572;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->AF.bytes.high == 0x7F) ? true : false;
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "INC A"
       };
    (*instructions)[oc] = i;

    // DEC A
    oc = 573;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->AF.bytes.high == 0x80) ? true : false;
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DEC A"
       };
    (*instructions)[oc] = i;

    // LD A,n
    oc = 574;
    i = { 11, 11, 1, INST{ z->getRegisters()->AF.bytes.high = d[0]; },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "LD A,n"
    };    (*instructions)[oc] = i;

    // CCF
    oc = 575;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            bool prevCarry = r->AF.bytes.low.CF;
            r->AF.bytes.low.CF = (r->AF.bytes.low.CF) ? false : true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = prevCarry;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CCF"
       };
    (*instructions)[oc] = i;

    // LD B,B
    oc = 576;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,B"
   };    (*instructions)[oc] = i;

    // LD B,C
    oc = 577;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,C"
    };    (*instructions)[oc] = i;

    // LD B,D
    oc = 578;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,D"
    };    (*instructions)[oc] = i;

    // LD B,E
    oc = 579;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,E"
    };    (*instructions)[oc] = i;

    // LD B,IYH
    oc = 580;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->IY.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,IYH"
    };    (*instructions)[oc] = i;

    // LD B,IYL
    oc = 581;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->IY.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,IYL"
    };    (*instructions)[oc] = i;

    // LD B,(IY+d)
    oc = 582;
    i = { 19, 19, 1, INST{
            z->getRegisters()->BC.bytes.high = (*m)[z->getRegisters()->IY.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD B,(IY+d)"
       };
    (*instructions)[oc] = i;

    // LD B,A
    oc = 583;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.high = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD B,A"
    };    (*instructions)[oc] = i;

    // LD C,B
    oc = 584;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,B"
    };    (*instructions)[oc] = i;

    // LD C,C
    oc = 585;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,C"
    };    (*instructions)[oc] = i;

    // LD C,D
    oc = 586;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,D"
    };    (*instructions)[oc] = i;

    // LD C,E
    oc = 587;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,E"
    };    (*instructions)[oc] = i;

    // LD C,IYH
    oc = 588;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->IY.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,IYH"
    };    (*instructions)[oc] = i;

    // LD C,IYL
    oc = 589;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->IY.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,IYL"
    };    (*instructions)[oc] = i;

    // LD C,(IY+d)
    oc = 590;
    i = { 19, 19, 1, INST{
            z->getRegisters()->BC.bytes.low = (*m)[z->getRegisters()->IY.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD C,(IY+d)"
       };
    (*instructions)[oc] = i;

    // LD C,A
    oc = 591;
    i = { 8, 8, 0, INST{ z->getRegisters()->BC.bytes.low = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD C,A"
    };    (*instructions)[oc] = i;

    // LD D,B
    oc = 592;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,B"
    };    (*instructions)[oc] = i;

    // LD D,C
    oc = 593;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,C"
    };    (*instructions)[oc] = i;

    // LD D,D
    oc = 594;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,D"
    };    (*instructions)[oc] = i;

    // LD D,E
    oc = 595;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,E"
    };    (*instructions)[oc] = i;

    // LD D,IYH
    oc = 596;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->IY.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,IYH"
    };    (*instructions)[oc] = i;

    // LD D,IYL
    oc = 597;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->IY.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,IYL"
    };    (*instructions)[oc] = i;

    // LD D,(IY+d)
    oc = 598;
    i = { 19, 19, 1, INST{
            z->getRegisters()->DE.bytes.high = (*m)[z->getRegisters()->IY.word+((int8_t)(d[0]))];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD D,(IY+d)"
       };
    (*instructions)[oc] = i;

    // LD D,A
    oc = 599;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.high = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD D,A"
    };    (*instructions)[oc] = i;

    // LD E,B
    oc = 600;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,B"
    };    (*instructions)[oc] = i;

    // LD E,C
    oc = 601;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,C"
    };    (*instructions)[oc] = i;

    // LD E,D
    oc = 602;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,D"
    };    (*instructions)[oc] = i;

    // LD E,E
    oc = 603;
    i = { 8, 8, 0, INST{; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,E"
    };    (*instructions)[oc] = i;

    // LD E,IYH
    oc = 604;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->IY.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,IYH"
    };    (*instructions)[oc] = i;

    // LD E,IYL
    oc = 605;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->IY.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,IYL"
    };    (*instructions)[oc] = i;

    // LD E,(IY+d)
    oc = 606;
    i = { 19, 19, 1, INST{
            z->getRegisters()->DE.bytes.low = (*m)[z->getRegisters()->IY.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD E,(IY+d)"
       };
    (*instructions)[oc] = i;

    // LD E,A
    oc = 607;
    i = { 8, 8, 0, INST{ z->getRegisters()->DE.bytes.low = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD E,A"
    };    (*instructions)[oc] = i;

    // LD IYH,B
    oc = 608;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.high = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYH,B"
    };    (*instructions)[oc] = i;

    // LD IYH,C
    oc = 609;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYH,C"
    };    (*instructions)[oc] = i;

    // LD IYH,D
    oc = 610;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.high = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYH,D"
    };    (*instructions)[oc] = i;

    // LD IYH,E
    oc = 611;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYH,E"
    };    (*instructions)[oc] = i;

    // LD IYH,IYH
    oc = 612;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYH,IYH"
    };    (*instructions)[oc] = i;

    // LD IYH,IYL
    oc = 613;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.high = z->getRegisters()->IY.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYH,IYL"
    };    (*instructions)[oc] = i;

    // LD H,(IY+d)
    oc = 614;
    i = { 19, 19, 1, INST{
            z->getRegisters()->HL.bytes.high = (*m)[z->getRegisters()->IY.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD H,(IY+d)"
       };
    (*instructions)[oc] = i;

    // LD IYH,A
    oc = 615;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.high = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYH,A"
    };    (*instructions)[oc] = i;

    // LD IYL,B
    oc = 616;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.low = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYL,B"
    };    (*instructions)[oc] = i;

    // LD IYL,C
    oc = 617;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.low = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYL,C"
    };    (*instructions)[oc] = i;

    // LD IYL,D
    oc = 618;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.low = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYL,D"
    };    (*instructions)[oc] = i;

    // LD IYL,E
    oc = 619;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.low = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYL,E"
    };    (*instructions)[oc] = i;

    // LD IYL,IYH
    oc = 620;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.low = z->getRegisters()->IY.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYL,IYH"
    };    (*instructions)[oc] = i;

    // LD IYL,IYL
    oc = 621;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYL,IYL"
    };    (*instructions)[oc] = i;

    // LD L,(IY+d)
    oc = 622;
    i = { 19, 19, 1, INST{
            z->getRegisters()->HL.bytes.low = (*m)[z->getRegisters()->IY.word+((int8_t)(d[0]))];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD L,(IY+d)"
       };
    (*instructions)[oc] = i;

    // LD IYL,A
    oc = 623;
    i = { 8, 8, 0, INST{ z->getRegisters()->IY.bytes.low = z->getRegisters()->AF.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD IYL,A"
    };    (*instructions)[oc] = i;

    // LD (IY+d),B
    oc = 624;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = z->getRegisters()->BC.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IY+d),B"
       };
    (*instructions)[oc] = i;

    // LD (IY+d),C
    oc = 625;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = z->getRegisters()->BC.bytes.low;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IY+d),C"
       };
    (*instructions)[oc] = i;

    // LD (IY+d),D
    oc = 626;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = z->getRegisters()->DE.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IY+d),D"
       };
    (*instructions)[oc] = i;

    // LD (IY+d),E
    oc = 627;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = z->getRegisters()->DE.bytes.low;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IY+d),E"
       };
    (*instructions)[oc] = i;

    // LD (IY+d),H
    oc = 628;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = z->getRegisters()->HL.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IY+d),H"
       };
    (*instructions)[oc] = i;

    // LD (IY+d),L
    oc = 629;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = z->getRegisters()->HL.bytes.low;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IY+d),L"
       };
    (*instructions)[oc] = i;

    // HALT
    oc = 630;
    i = { 8, 8, 0, INST{
            z->halt();
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "HALT"
       };
    (*instructions)[oc] = i;

    // LD (IY+d),A
    oc = 631;
    i = { 19, 19, 1, INST{
            (*m)[z->getRegisters()->IY.word+((int8_t)d[0])] = z->getRegisters()->AF.bytes.high;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD (IY+d),A"
       };
    (*instructions)[oc] = i;

    // LD A,B
    oc = 632;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->BC.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,B"
    };    (*instructions)[oc] = i;

    // LD A,C
    oc = 633;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->BC.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,C"
    };    (*instructions)[oc] = i;

    // LD A,D
    oc = 634;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->DE.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,D"
    };    (*instructions)[oc] = i;

    // LD A,E
    oc = 635;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->DE.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,E"
    };    (*instructions)[oc] = i;

    // LD A,IYH
    oc = 636;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->IY.bytes.high; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,IYH"
    };    (*instructions)[oc] = i;

    // LD A,IYL
    oc = 637;
    i = { 8, 8, 0, INST{ z->getRegisters()->AF.bytes.high = z->getRegisters()->IY.bytes.low; },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,IYL"
    };    (*instructions)[oc] = i;

    // LD A,(IY+d)
    oc = 638;
    i = { 19, 19, 1, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->IY.word+((int8_t)d[0])];
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "LD A,(IY+d)"
       };
    (*instructions)[oc] = i;

    // LD A,A
    oc = 639;
    i = { 8, 8, 0, INST{ ; /* Practically a NOP */ },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "LD A,A"
    };    (*instructions)[oc] = i;

    // ADD A,B
    oc = 640;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,B"
       };
    (*instructions)[oc] = i;

    // ADD A,C
    oc = 641;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,C"
       };
    (*instructions)[oc] = i;

    // ADD A,D
    oc = 642;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,D"
       };
    (*instructions)[oc] = i;

    // ADD A,E
    oc = 643;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,E"
       };
    (*instructions)[oc] = i;

    // ADD A,IYH
    oc = 644;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IY.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,IYH"
       };
    (*instructions)[oc] = i;

    // ADD A,IYL
    oc = 645;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IY.bytes.low, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,IYL"
       };
    (*instructions)[oc] = i;

    // ADD A,(IY+d)
    oc = 646;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, (*m)[z->getRegisters()->IY.word+((int8_t)d[0])], r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "ADD A,(IY+d)"
       };
    (*instructions)[oc] = i;

    // ADD A,A
    oc = 647;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->AF.bytes.high, r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADD A,A"
       };
    (*instructions)[oc] = i;

    // ADC A,B
    oc = 648;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,B"
       };
    (*instructions)[oc] = i;

    // ADC A,C
    oc = 649;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->BC.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,C"
       };
    (*instructions)[oc] = i;

    // ADC A,D
    oc = 650;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,D"
       };
    (*instructions)[oc] = i;

    // ADC A,E
    oc = 651;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->DE.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,E"
       };
    (*instructions)[oc] = i;

    // ADC A,IYH
    oc = 652;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IY.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,IYH"
       };
    (*instructions)[oc] = i;

    // ADC A,IYL
    oc = 653;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->IY.bytes.low, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,IYL"
       };
    (*instructions)[oc] = i;

    // ADC A,(IY+d)
    oc = 654;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, (*m)[z->getRegisters()->IY.word+((int8_t)d[0])], r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "ADC A,(IY+d)"
       };
    (*instructions)[oc] = i;

    // ADC A,A
    oc = 655;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, r->AF.bytes.high, r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "ADC A,A"
       };
    (*instructions)[oc] = i;

    // SUB B
    oc = 656;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB B"
       };
    (*instructions)[oc] = i;

    // SUB C
    oc = 657;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB C"
       };
    (*instructions)[oc] = i;

    // SUB D
    oc = 658;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB D"
       };
    (*instructions)[oc] = i;

    // SUB E
    oc = 659;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB E"
       };
    (*instructions)[oc] = i;

    // SUB IYH
    oc = 660;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IY.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB IYH"
       };
    (*instructions)[oc] = i;

    // SUB IYL
    oc = 661;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IY.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB IYL"
       };
    (*instructions)[oc] = i;

    // SUB (IY+d)
    oc = 662;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->IY.word+((int8_t)d[0])]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "SUB (IY+d)"
       };
    (*instructions)[oc] = i;

    // SUB A
    oc = 663;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SUB A"
       };
    (*instructions)[oc] = i;

    // SBC A,B
    oc = 664;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,B"
       };
    (*instructions)[oc] = i;

    // SBC A,C
    oc = 665;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,C"
       };
    (*instructions)[oc] = i;

    // SBC A,D
    oc = 666;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,D"
       };
    (*instructions)[oc] = i;

    // SBC A,E
    oc = 667;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,E"
       };
    (*instructions)[oc] = i;

    // SBC A,IYH
    oc = 668;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IY.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,IYH"
       };
    (*instructions)[oc] = i;

    // SBC A,IYL
    oc = 669;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->IY.bytes.low), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,IYL"
       };
    (*instructions)[oc] = i;

    // SBC A,(IY+d)
    oc = 670;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->IY.word+((int8_t)d[0])]), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "SBC A,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SBC A,A
    oc = 671;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SBC A,A"
       };
    (*instructions)[oc] = i;

    // AND B
    oc = 672;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND B"
       };
    (*instructions)[oc] = i;

    // AND C
    oc = 673;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND C"
       };
    (*instructions)[oc] = i;

    // AND D
    oc = 674;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND D"
       };
    (*instructions)[oc] = i;

    // AND E
    oc = 675;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND E"
       };
    (*instructions)[oc] = i;

    // AND IYH
    oc = 676;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->IY.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND IYH"
       };
    (*instructions)[oc] = i;

    // AND IYL
    oc = 677;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->IY.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND IYL"
       };
    (*instructions)[oc] = i;

    // AND (IY+d)
    oc = 678;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, (*m)[z->getRegisters()->IY.word+((int8_t)d[0])], r);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "AND (IY+d)"
       };
    (*instructions)[oc] = i;

    // AND A
    oc = 679;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "AND A"
       };
    (*instructions)[oc] = i;

    // XOR B
    oc = 680;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR B"
       };
    (*instructions)[oc] = i;

    // XOR C
    oc = 681;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR C"
       };
    (*instructions)[oc] = i;

    // XOR D
    oc = 682;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR D"
       };
    (*instructions)[oc] = i;

    // XOR E
    oc = 683;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR E"
       };
    (*instructions)[oc] = i;

    // XOR IYH
    oc = 684;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->IY.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR IYH"
       };
    (*instructions)[oc] = i;

    // XOR IYL
    oc = 685;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->IY.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR IYL"
       };
    (*instructions)[oc] = i;

    // XOR (IY+d)
    oc = 686;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, (*m)[z->getRegisters()->IY.word+((int8_t)d[0])], r);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "XOR (IY+d)"
       };
    (*instructions)[oc] = i;

    // XOR A
    oc = 687;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "XOR A"
       };
    (*instructions)[oc] = i;

    // OR B
    oc = 688;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR B"
       };
    (*instructions)[oc] = i;

    // OR C
    oc = 689;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR C"
       };
    (*instructions)[oc] = i;

    // OR D
    oc = 690;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR D"
       };
    (*instructions)[oc] = i;

    // OR E
    oc = 691;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR E"
       };
    (*instructions)[oc] = i;

    // OR IYH
    oc = 692;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->IY.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR IYH"
       };
    (*instructions)[oc] = i;

    // OR IYL
    oc = 693;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->IY.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR IYL"
       };
    (*instructions)[oc] = i;

    // OR (IY+d)
    oc = 694;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, (*m)[z->getRegisters()->IY.word+((int8_t)d[0])], r);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "OR (IY+d)"
       };
    (*instructions)[oc] = i;

    // OR A
    oc = 695;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "OR A"
       };
    (*instructions)[oc] = i;

    // CP B
    oc = 696;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP B"
       };
    (*instructions)[oc] = i;

    // CP C
    oc = 697;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->BC.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP C"
       };
    (*instructions)[oc] = i;

    // CP D
    oc = 698;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP D"
       };
    (*instructions)[oc] = i;

    // CP E
    oc = 699;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->DE.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP E"
       };
    (*instructions)[oc] = i;

    // CP IYH
    oc = 700;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->IY.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP IYH"
       };
    (*instructions)[oc] = i;

    // CP IYL
    oc = 701;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->IY.bytes.low), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP IYL"
       };
    (*instructions)[oc] = i;

    // CP (IY+d)
    oc = 702;
    i = { 19, 19, 1, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -((*m)[z->getRegisters()->IY.word+((int8_t)d[0])]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 3, 0, 0 },
        "CP (IY+d)"
       };
    (*instructions)[oc] = i;

    // CP A
    oc = 703;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(r->AF.bytes.high), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "CP A"
       };
    (*instructions)[oc] = i;

    // RET NZ
    oc = 704;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::NZ);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET NZ"
       };
    (*instructions)[oc] = i;

    // POP BC
    oc = 705;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP BC"
       };
    (*instructions)[oc] = i;

    // JP NZ,nn
    oc = 706;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.ZF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP NZ,nn"
       };
    (*instructions)[oc] = i;

    // JP nn
    oc = 707;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            r->PC = nn;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP nn"
       };
    (*instructions)[oc] = i;

    // CALL NZ,nn
    oc = 708;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::NZ, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL NZ,nn"
       };
    (*instructions)[oc] = i;

    // PUSH BC
    oc = 709;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->BC.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->BC.bytes.low;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH BC"
       };
    (*instructions)[oc] = i;

    // ADD A,n
    oc = 710;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, d[0], r, ADD8);
            r->AF.bytes.low.NF = 0;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADD A,n"
       };
    (*instructions)[oc] = i;

    // RST 00
    oc = 711;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x00;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 00"
       };
    (*instructions)[oc] = i;

    // RET Z
    oc = 712;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::Z);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET Z"
       };
    (*instructions)[oc] = i;

    // RET
    oc = 713;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0 | (*m)[r->SP];
            r->SP++;
            r->PC |= ((*m)[r->SP]) << 8;
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RET"
       };
    (*instructions)[oc] = i;

    // JP Z,nn
    oc = 714;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.ZF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP Z,nn"
       };
    (*instructions)[oc] = i;

    // 0x00CB is prefix

    // CALL Z,nn
    oc = 716;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::Z, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL Z,nn"
       };
    (*instructions)[oc] = i;

    // CALL nn
    oc = 717;
    i = { 21, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            r->SP--;
            (*m)[r->SP] = (r->PC) >> 8;
            r->SP--;
            (*m)[r->SP] = (r->PC) & 0xFF;
            r->PC = nn;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL nn"
       };
    (*instructions)[oc] = i;

    // ADC A,n
    oc = 718;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add(r->AF.bytes.high, d[0], r, ADD8, true);
            r->AF.bytes.low.NF = 0;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "ADC A,n"
       };
    (*instructions)[oc] = i;

    // RST 08
    oc = 719;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x08;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 08"
       };
    (*instructions)[oc] = i;

    // RET NC
    oc = 720;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::NC);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET NC"
       };
    (*instructions)[oc] = i;

    // POP DE
    oc = 721;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP DE"
       };
    (*instructions)[oc] = i;

    // JP NC,nn
    oc = 722;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.CF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP NC,nn"
       };
    (*instructions)[oc] = i;

    // OUT (n),A
    oc = 723;
    i = { 15, 15, 1, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(d[0], r->AF.bytes.high)] = r->AF.bytes.high;
            z->getIoPorts()->writeToPort(CREATE_WORD(d[0], r->AF.bytes.high), r->AF.bytes.high);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 0, 0, 0 },
        "OUT (n),A"
       };
    (*instructions)[oc] = i;

    // CALL NC,nn
    oc = 724;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::NC, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL NC,nn"
       };
    (*instructions)[oc] = i;

    // PUSH DE
    oc = 725;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->DE.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->DE.bytes.low;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH DE"
       };
    (*instructions)[oc] = i;

    // SUB n
    oc = 726;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "SUB n"
       };
    (*instructions)[oc] = i;

    // RST 10
    oc = 727;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x10;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 10"
       };
    (*instructions)[oc] = i;

    // RET C
    oc = 728;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::C);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET C"
       };
    (*instructions)[oc] = i;

    // EXX
    oc = 729;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->BC.word;
            r->BC.word = r->BCx.word;
            r->BCx.word = tmp;
            tmp = r->DE.word;
            r->DE.word = r->DEx.word;
            r->DEx.word = tmp;
            tmp = r->HL.word;
            r->HL.word = r->HLx.word;
            r->HLx.word = tmp;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EXX"
       };
    (*instructions)[oc] = i;

    // JP C,nn
    oc = 730;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.CF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP C,nn"
       };
    (*instructions)[oc] = i;

    // IN A,(n)
    oc = 731;
    i = { 15, 15, 1, INST{
            Z80Registers* r = z->getRegisters();
            // r->AF.bytes.high = (*(z->getIoPorts()))[CREATE_WORD(d[0], r->AF.bytes.high)];
            r->AF.bytes.high = z->getIoPorts()->readPort(CREATE_WORD(d[0], r->AF.bytes.high));
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 0, 0, 0 },
        "IN A,(n)"
       };
    (*instructions)[oc] = i;

    // CALL C,nn
    oc = 732;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::C, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL C,nn"
       };
    (*instructions)[oc] = i;

    // 0xFD is prefix

    // SBC A,n
    oc = 734;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8, false, true);
            r->AF.bytes.low.NF = 1;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "SBC A,n"
       };
    (*instructions)[oc] = i;

    // RST 18
    oc = 735;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x18;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 18"
       };
    (*instructions)[oc] = i;

    // RET PO
    oc = 736;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::PO);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET PO"
       };
    (*instructions)[oc] = i;

    // POP IY
    oc = 737;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IY.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP IY"
       };
    (*instructions)[oc] = i;

    // JP PO,nn
    oc = 738;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.PF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP PO,nn"
       };
    (*instructions)[oc] = i;

    // EX (SP),IY
    oc = 739;
    i = { 23, 23, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t tmp = r->IY.bytes.low;
            r->IY.bytes.low = (*m)[r->SP];
            (*m)[r->SP] = tmp;
            tmp = r->IY.bytes.high;
            r->IY.bytes.high = (*m)[(r->SP)+1];
            (*m)[(r->SP)+1] = tmp;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 5, 0 },
        "EX (SP),IY"
       };
    (*instructions)[oc] = i;

    // CALL PO,nn
    oc = 740;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::PO, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL PO,nn"
       };
    (*instructions)[oc] = i;

    // PUSH IY
    oc = 741;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->IY.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->IY.bytes.low;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH IY"
       };
    (*instructions)[oc] = i;

    // AND n
    oc = 742;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = and(r->AF.bytes.high, d[0], r);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "AND n"
       };
    (*instructions)[oc] = i;

    // RST 20
    oc = 743;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x20;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 20"
       };
    (*instructions)[oc] = i;

    // RET PE
    oc = 744;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::PE);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET PE"
       };
    (*instructions)[oc] = i;

    // JP,(IY)
    oc = 745;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->PC = (*m)[r->IY.word];
            r->PC = r->IY.word;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "JP,(IY)"
       };
    (*instructions)[oc] = i;

    // JP PE,nn
    oc = 746;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.PF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP PE,nn"
       };
    (*instructions)[oc] = i;

    // EX DE,HL
    oc = 747;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t tmp = r->DE.word;
            r->DE.word = r->HL.word;
            r->HL.word = tmp;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EX DE,HL"
       };
    (*instructions)[oc] = i;

    // CALL PE,nn
    oc = 748;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::PE, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL PE,nn"
       };
    (*instructions)[oc] = i;

    // 0xED is prefix

    // XOR n
    oc = 750;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = xor(r->AF.bytes.high, d[0], r);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "XOR n"
       };
    (*instructions)[oc] = i;

    // RST 28
    oc = 751;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x28;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 28"
       };
    (*instructions)[oc] = i;

    // RET P
    oc = 752;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::P);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET P"
       };
    (*instructions)[oc] = i;

    // POP AF
    oc = 753;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.word = CREATE_WORD((*m)[(r->SP)++], (*m)[r->SP]);
            r->SP++;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "POP AF"
       };
    (*instructions)[oc] = i;

    // JP P,nn
    oc = 754;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (!(r->AF.bytes.low.SF))
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP P,nn"
       };
    (*instructions)[oc] = i;

    // DI
    oc = 755;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            z->setIFF1(false);
            z->setIFF2(false);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "DI"
       };
    (*instructions)[oc] = i;

    // CALL P,nn
    oc = 756;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::P, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL P,nn"
       };
    (*instructions)[oc] = i;

    // PUSH AF
    oc = 757;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->AF.bytes.high;
            r->SP--;
            (*m)[r->SP] = r->AF.bytes.low.byte;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "PUSH AF"
       };
    (*instructions)[oc] = i;

    // OR n
    oc = 758;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = or(r->AF.bytes.high, d[0], r);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "OR n"
       };
    (*instructions)[oc] = i;

    // RST 30
    oc = 759;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x30;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 30"
       };
    (*instructions)[oc] = i;

    // RET M
    oc = 760;
    i = { 9, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            retc(r, m, RetCondition::M);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RET M"
       };
    (*instructions)[oc] = i;

    // LD SP,IY
    oc = 761;
    i = { 10, 10, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP = r->IY.word;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 6, 0, 0, 0, 0, 0 },
        "LD SP,IY"
       };
    (*instructions)[oc] = i;

    // JP M,nn
    oc = 762;
    i = { 14, 14, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            if (r->AF.bytes.low.SF)
            {
                r->PC = nn;
            }
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "JP M,nn"
       };
    (*instructions)[oc] = i;

    // EI
    oc = 763;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            z->setIFF1(true);
            z->setIFF2(true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "EI"
       };
    (*instructions)[oc] = i;

    // CALL M,nn
    oc = 764;
    i = { 14, 21, 2, INST{
            Z80Registers* r = z->getRegisters();
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            callc(r, m, RetCondition::M, nn);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 3, 0 },
        "CALL M,nn"
       };
    (*instructions)[oc] = i;

    // 0xFD is prefix

    // CP n
    oc = 766;
    i = { 11, 11, 1, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -(d[0]), r, SUB8);
            r->AF.bytes.low.NF = 1;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 0, 0, 0, 0 },
        "CP n"
       };
    (*instructions)[oc] = i;

    // RST 38
    oc = 767;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->SP--;
            (*m)[r->SP] = r->PC >> 8;
            r->SP--;
            (*m)[r->SP] = r->PC & 0xFF;
            r->PC = 0 | 0x38;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 3, 0, 0, 0 },
        "RST 38"
       };
    (*instructions)[oc] = i;

    /* 0xED00 - 0xED3F are NOPs */

    // IN B,(C)
    oc = 832;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->BC.bytes.high = (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)];
            r->BC.bytes.high = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = r->BC.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.high == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.high);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN B,(C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),B
    oc = 833;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)] = r->BC.bytes.high;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), r->BC.bytes.high);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),B"
       };
    (*instructions)[oc] = i;

    // SBC HL,BC
    oc = 834;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, -(r->BC.word), r, SUB16, false, true);
            r->AF.bytes.low.NF = 1;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SBC HL,BC"
       };
    (*instructions)[oc] = i;

    // LD (nn),BC
    oc = 835;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->BC.bytes.low;
            (*m)[nn+1] = z->getRegisters()->BC.bytes.high;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD (nn),BC"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 836;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETN
    oc = 837;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETN"
       };
    (*instructions)[oc] = i;

    // IM 0
    oc = 838;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(0);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 0"
       };
    (*instructions)[oc] = i;

    // LD I,A
    oc = 839;
    i = { 9, 9, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IR.bytes.high = r->AF.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 0, 0, 0, 0, 0 },
        "LD I,A"
       };
    (*instructions)[oc] = i;

    // IN C,(C)
    oc = 840;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->BC.bytes.low = (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)];
            r->BC.bytes.low = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = r->BC.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.low == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.low);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN C,(C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),C
    oc = 841;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)] = r->BC.bytes.low;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), r->BC.bytes.low);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),C"
       };
    (*instructions)[oc] = i;

    // ADC HL,BC
    oc = 842;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->HL.word = add<uint16_t>(r->HL.word, r->BC.word, r, ADD16, false, true);
            r->HL.word = add<uint16_t>(r->HL.word, r->BC.word, r, ADC16, true);
            r->AF.bytes.low.NF = 0;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADC HL,BC"
       };
    (*instructions)[oc] = i;

    // LD BC,(nn)
    oc = 843;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            z->getRegisters()->BC.bytes.low = (*m)[nn];
            z->getRegisters()->BC.bytes.high = (*m)[nn+1];
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD BC,(nn)"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 844;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETI
    oc = 845;
    i = { 14, 14, 0, INST{
            // Only differs from RETN in opcode
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETI"
       };
    (*instructions)[oc] = i;

    // IM 0
    oc = 846;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(0);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 0"
       };
    (*instructions)[oc] = i;

    // LD R,A
    oc = 847;
    i = { 9, 9, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->IR.bytes.low = r->AF.bytes.high;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 0, 0, 0, 0, 0 },
        "LD R,A"
       };
    (*instructions)[oc] = i;

    // IN D,(C)
    oc = 848;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->DE.bytes.high = (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)];¨
            r->DE.bytes.high = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = r->DE.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.high == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.high);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN D,(C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),D
    oc = 849;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)] = r->DE.bytes.high;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), r->DE.bytes.high);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),D"
       };
    (*instructions)[oc] = i;

    // SBC HL,DE
    oc = 850;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, -(r->DE.word), r, SUB16, false, true);
            r->AF.bytes.low.NF = 1;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SBC HL,DE"
       };
    (*instructions)[oc] = i;

    // LD (nn),DE
    oc = 851;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->DE.bytes.low;
            (*m)[nn+1] = z->getRegisters()->DE.bytes.high;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD (nn),DE"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 852;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETN
    oc = 853;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETN"
       };
    (*instructions)[oc] = i;

    // IM 1
    oc = 854;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(1);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 1"
       };
    (*instructions)[oc] = i;

    // LD A,I
    oc = 855;
    i = { 9, 9, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = r->IR.bytes.high;
            r->AF.bytes.low.SF = r->IR.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->IR.bytes.high == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = z->getIFF2();
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 0, 0, 0, 0, 0 },
        "LD A,I"
       };
    (*instructions)[oc] = i;

    // IN E,(C)
    oc = 856;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->DE.bytes.low = (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)];
            r->DE.bytes.low = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = r->DE.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.low == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.low);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN E,(C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),E
    oc = 857;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)] = r->DE.bytes.low;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), r->DE.bytes.low);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),E"
       };
    (*instructions)[oc] = i;

    // ADC HL,DE
    oc = 858;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, r->DE.word, r, ADC16, true);
            r->AF.bytes.low.NF = 0;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADC HL,DE"
       };
    (*instructions)[oc] = i;

    // LD DE,(nn)
    oc = 859;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            z->getRegisters()->DE.bytes.low = (*m)[nn];
            z->getRegisters()->DE.bytes.high = (*m)[nn+1];
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD DE,(nn)"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 860;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETI
    oc = 861;
    i = { 14, 14, 0, INST{
            // Only differs from RETN in opcode
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETI"
       };
    (*instructions)[oc] = i;

    // IM 2
    oc = 862;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(2);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 2"
       };
    (*instructions)[oc] = i;

    // LD A,R
    oc = 863;
    i = { 9, 9, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high = r->IR.bytes.low;
            r->AF.bytes.low.SF = r->IR.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->IR.bytes.low == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = z->getIFF2();
            r->AF.bytes.low.NF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 0, 0, 0, 0, 0 },
        "LD A,R"
       };
    (*instructions)[oc] = i;

    // IN H,(C)
    oc = 864;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->HL.bytes.high = (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)];
            r->HL.bytes.high = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = r->HL.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.high == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.high);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN H,(C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),H
    oc = 865;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)] = r->HL.bytes.high;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), r->HL.bytes.high);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),H"
       };
    (*instructions)[oc] = i;

    // SBC HL,HL
    oc = 866;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, -(r->HL.word), r, SUB16, false, true);
            r->AF.bytes.low.NF = 1;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SBC HL,HL"
       };
    (*instructions)[oc] = i;

    // LD (nn),HL
    oc = 867;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->HL.bytes.low;
            (*m)[nn+1] = z->getRegisters()->HL.bytes.high;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD (nn),HL"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 868;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETN
    oc = 869;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETN"
       };
    (*instructions)[oc] = i;

    // IM 0
    oc = 870;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(0);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 0"
       };
    (*instructions)[oc] = i;

    // RRD
    oc = 871;
    i = { 18, 18, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t lowHlMem = ((*m)[r->HL.word]) & 0xF;
            uint8_t lowAcc = r->AF.bytes.high & 0xF;
            uint8_t highHlMem = ((*m)[r->HL.word]) >> 4;
            r->AF.bytes.high &= 0xF0;
            r->AF.bytes.high |= lowHlMem;
            (*m)[r->HL.word] = 0;
            (*m)[r->HL.word] |= lowAcc << 4;
            (*m)[r->HL.word] |= highHlMem;
            r->AF.bytes.low.SF = r->AF.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->AF.bytes.high == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 0, 0 },
        "RRD"
       };
    (*instructions)[oc] = i;

    // IN L,(C)
    oc = 872;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->HL.bytes.low = (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)];
            r->HL.bytes.low = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = r->HL.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.low == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.low);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN L,(C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),L
    oc = 873;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)] = r->HL.bytes.low;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), r->HL.bytes.low);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),L"
       };
    (*instructions)[oc] = i;

    // ADC HL,HL
    oc = 874;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, r->HL.word, r, ADC16, true);
            r->AF.bytes.low.NF = 0;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADC HL,HL"
       };
    (*instructions)[oc] = i;

    // LD HL,(nn)
    oc = 875;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            z->getRegisters()->HL.bytes.low = (*m)[nn];
            z->getRegisters()->HL.bytes.high = (*m)[nn+1];
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD HL,(nn)"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 876;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETI
    oc = 877;
    i = { 14, 14, 0, INST{
            // Only differs from RETN in opcode
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETI"
       };
    (*instructions)[oc] = i;

    // IM 0
    oc = 878;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(2);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 0"
       };
    (*instructions)[oc] = i;

    // RLD
    oc = 879;
    i = { 18, 18, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t lowHlMem = ((*m)[r->HL.word]) & 0xF;
            uint8_t lowAcc = r->AF.bytes.high & 0xF;
            uint8_t highHlMem = ((*m)[r->HL.word]) >> 4;
            r->AF.bytes.high &= 0xF0;
            r->AF.bytes.high |= highHlMem;
            (*m)[r->HL.word] = 0;
            (*m)[r->HL.word] |= lowHlMem << 4;
            (*m)[r->HL.word] |= lowAcc;
            r->AF.bytes.low.SF = r->AF.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->AF.bytes.high == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 4, 3, 0, 0 },
        "RLD"
       };
    (*instructions)[oc] = i;

    // IN (C)
    oc = 880;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->HL.bytes.low = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = (z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high))) >> 7;
            r->AF.bytes.low.ZF = (z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high))) == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)));
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN (C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),0
    oc = 881;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[r->BC.bytes.low] = 0;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), 0);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),0"
       };
    (*instructions)[oc] = i;

    // SBC HL,SP
    oc = 882;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, -(r->SP), r, SUB16, false, true);
            r->AF.bytes.low.NF = 1;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SBC HL,SP"
       };
    (*instructions)[oc] = i;

    // LD (nn),SP
    oc = 883;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = (uint8_t) (z->getRegisters()->SP & 0xFF);
            (*m)[nn+1] = (uint8_t) (z->getRegisters()->SP >> 8);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD (nn),SP"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 884;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETN
    oc = 885;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETN"
       };
    (*instructions)[oc] = i;

    // IM 1
    oc = 886;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(1);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 1"
       };
    (*instructions)[oc] = i;

    // 0xED77 is NOP

    // IN A,(C)
    oc = 888;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // r->AF.bytes.high = (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)];
            r->AF.bytes.high = z->getIoPorts()->readPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high));
            r->AF.bytes.low.SF = r->AF.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->AF.bytes.high == 0;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->AF.bytes.high);
            r->AF.bytes.low.NF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "IN A,(C)"
       };
    (*instructions)[oc] = i;

    // OUT (C),A
    oc = 889;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high)] = r->AF.bytes.high;
            z->getIoPorts()->writeToPort(CREATE_WORD(r->BC.bytes.low, r->BC.bytes.high), r->AF.bytes.high);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "OUT (C),A"
       };
    (*instructions)[oc] = i;

    // ADC HL,SP
    oc = 890;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, r->SP, r, ADC16, true);
            r->AF.bytes.low.NF = 0;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "ADC HL,SP"
       };
    (*instructions)[oc] = i;

    // LD SP,(nn)
    oc = 891;
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            Z80Registers* r = z->getRegisters();
            r->SP = 0;
            r->SP |= (*m)[nn];
            r->SP |= ((uint16_t)((*m)[nn+1])) << 8;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 3, 3, 0 },
        "LD SP,(nn)"
       };
    (*instructions)[oc] = i;

    // NEG
    oc = 892;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            if ( r->AF.bytes.high == 0x80 ) { r->AF.bytes.low.PF = true; }
            else { r->AF.bytes.low.PF = false; }
            r->AF.bytes.low.CF = r->AF.bytes.high != 0x00;
            r->AF.bytes.high = add<uint8_t>(0, -(r->AF.bytes.high), r, NEG8);
            r->AF.bytes.low.NF = true;

        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "NEG"
       };
    (*instructions)[oc] = i;

    // RETI
    oc = 893;
    i = { 14, 14, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->PC = 0;
            r->PC |= (*m)[r->SP];
            r->SP++;
            r->PC |= (*m)[r->SP] << 8;
            r->SP++;
            z->setIFF1(z->getIFF2());
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 3, 0, 0, 0 },
        "RETI"
       };
    (*instructions)[oc] = i;

    // IM 2
    oc = 894;
    i = { 8, 8, 0, INST{
            z->setInterruptMode(2);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "IM 2"
       };
    (*instructions)[oc] = i;

    // 0xED7F - 0xED9F are NOPs

    // LDI
    oc = 928;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->DE.word] = (*m)[r->HL.word];
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            r->DE.word = add<uint16_t>(r->DE.word, 1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = r->BC.word != 0;
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "LDI"
       };
    (*instructions)[oc] = i;

    // CPI
    oc = 929;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -((*m)[r->HL.word]), r, SUB8_NOBORROW);
            r->AF.bytes.low.NF = 1;
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.PF = r->BC.word != 0;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "CPI"
       };
    (*instructions)[oc] = i;

    // INI
    oc = 930;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*m)[r->HL.word] = (*(z->getIoPorts()))[r->BC.bytes.low];
            (*m)[r->HL.word] = z->getIoPorts()->readPort(r->BC.word);
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            r->AF.bytes.low.ZF = r->BC.bytes.high != 0;
            r->AF.bytes.low.NF = true;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 4, 3, 0, 0, 0 },
        "INI"
       };
    (*instructions)[oc] = i;

    // OUTI
    oc = 931;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[r->BC.bytes.low] = (*m)[r->HL.word];
            z->getIoPorts()->writeToPort(r->BC.word, (*m)[r->HL.word]);
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            r->AF.bytes.low.ZF = r->BC.bytes.high == 0;
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 4, 0, 0, 0 },
        "OUTI"
       };
    (*instructions)[oc] = i;

    // LDD
    oc = 936;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->DE.word] = (*m)[r->HL.word];
            r->DE.word = add<uint16_t>(r->DE.word, -1, r, 0);
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = r->BC.word != 0;
            r->AF.bytes.low.NF = false;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "LDD"
       };
    (*instructions)[oc] = i;

    /* 0xEDA5 - 0xEDA7 are NOPs */

    // CPD
    oc = 937;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -((*m)[r->HL.word]), r, SUB8);
            r->AF.bytes.low.NF = 1;
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.PF = r->BC.word != 0;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 0, 0, 0 },
        "CPD"
       };
    (*instructions)[oc] = i;

    // IND
    oc = 938;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*m)[r->HL.word] = (*(z->getIoPorts()))[r->BC.bytes.low];
            (*m)[r->HL.word] = z->getIoPorts()->readPort(r->BC.word);
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, 0);
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            r->AF.bytes.low.ZF = r->BC.bytes.high != 0;
            r->AF.bytes.low.NF = true;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 4, 3, 0, 0, 0 },
        "IND"
       };
    (*instructions)[oc] = i;

    // OUTD
    oc = 939;
    i = { 16, 16, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[r->BC.bytes.low] = (*m)[r->HL.word];
            z->getIoPorts()->writeToPort(r->BC.word, (*m)[r->HL.word]);
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, SUB8_NOBORROW);
            r->AF.bytes.low.NF = true;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOW, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 4, 0, 0, 0 },
        "OUTD"
       };
    (*instructions)[oc] = i;

    // LDIR
    oc = 944;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->DE.word] = (*m)[r->HL.word];
            r->DE.word = add<uint16_t>(r->DE.word, 1, r, 0);
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = false;
            r->AF.bytes.low.NF = false;
            if (r->BC.word != 0)
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 5, 0, 0 },
        "LDIR"
       };
    (*instructions)[oc] = i;

    // CPIR
    oc = 945;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -((*m)[r->HL.word]), r, SUB8_NOBORROW);
            uint8_t old_hlMem = (*m)[r->HL.word];
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.PF = r->BC.word != 0;
            r->AF.bytes.low.NF = true;
            if (r->BC.word != 0 && r->AF.bytes.high != old_hlMem)
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 5, 0, 0 },
        "CPIR"
       };
    (*instructions)[oc] = i;

    // INIR
    oc = 946;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*m)[r->HL.word] = (*(z->getIoPorts()))[r->BC.bytes.low];
            (*m)[r->HL.word] = z->getIoPorts()->readPort(r->BC.word);
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            r->AF.bytes.low.ZF = true;
            r->AF.bytes.low.NF = true;
            if (r->BC.bytes.high != 0)
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::MWR, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 4, 3, 5, 0, 0 },
        "INIR"
       };
    (*instructions)[oc] = i;

    // OTIR
    oc = 947;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[r->BC.bytes.low] = (*m)[r->HL.word];
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, SUB8_NOBORROW);
            z->getIoPorts()->writeToPort(r->BC.word, (*m)[r->HL.word]);
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, 0);
            // r->AF.bytes.low.ZF = true;
            r->AF.bytes.low.NF = true;
            if (r->BC.bytes.high != 0)
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOW, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 4, 5, 0, 0 },
        "OTIR"
       };
    (*instructions)[oc] = i;

    /* 0xEDB4 - 0xEDB7 are NOPs */

    // LDDR
    oc = 952;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->DE.word] = (*m)[r->HL.word];
            r->DE.word = add<uint16_t>(r->DE.word, -1, r, 0);
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = false;
            r->AF.bytes.low.NF = false;
            if (r->BC.word != 0)
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 5, 0, 0 },
        "LDDR"
       };
    (*instructions)[oc] = i;

    // CPDR
    oc = 953;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            add<uint8_t>(r->AF.bytes.high, -((*m)[r->HL.word]), r, SUB8_NOBORROW);
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, 0);
            r->BC.word = add<uint16_t>(r->BC.word, -1, r, 0);
            r->AF.bytes.low.PF = r->BC.word != 0;
            r->AF.bytes.low.NF = true;
            if (r->BC.word != 0 && r->AF.bytes.high != (*m)[r->HL.word])
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::NON, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 5, 0, 0 },
        "CPDR"
       };
    (*instructions)[oc] = i;

    // INDR
    oc = 954;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*m)[r->HL.word] = (*(z->getIoPorts()))[r->BC.bytes.low];
            (*m)[r->HL.word] = z->getIoPorts()->readPort(r->BC.word);
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, 0);
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            r->AF.bytes.low.ZF = true;
            r->AF.bytes.low.NF = true;
            if (r->BC.bytes.high != 0)
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::IOR, MachineCycleType::MWR, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 4, 3, 5, 0, 0 },
        "INDR"
       };
    (*instructions)[oc] = i;

    // OTDR
    oc = 955;
    i = { 16, 21, 0, INST{
            Z80Registers* r = z->getRegisters();
            // (*(z->getIoPorts()))[r->BC.bytes.low] = (*m)[r->HL.word];
            z->getIoPorts()->writeToPort(r->BC.word, (*m)[r->HL.word]);
            r->HL.word = add<uint16_t>(r->HL.word, -1, r, 0);
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, SUB8_NOBORROW);
            // r->AF.bytes.low.ZF = true;
            r->AF.bytes.low.NF = true;
            if (r->BC.bytes.high != 0)
            {
                r->PC -= 2;
            }
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::IOW, MachineCycleType::NON, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 5, 3, 4, 5, 0, 0 },
        "OTDR"
       };
    (*instructions)[oc] = i;

    /* 0xEDBC - 0xEDFF are NOPs */

    // RLC B
    oc = 1024;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->BC.bytes.high >> 7) & 0x01);
            r->BC.bytes.high = rol<uint8_t>(r->BC.bytes.high);
            r->AF.bytes.low.SF = r->BC.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLC B"
       };
    (*instructions)[oc] = i;

    // RLC C
    oc = 1025;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->BC.bytes.low >> 7) & 0x01);
            r->BC.bytes.low = rol<uint8_t>(r->BC.bytes.low);
            r->AF.bytes.low.SF = r->BC.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLC C"
       };
    (*instructions)[oc] = i;

    // RLC D
    oc = 1026;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->DE.bytes.high >> 7) & 0x01);
            r->DE.bytes.high = rol<uint8_t>(r->DE.bytes.high);
            r->AF.bytes.low.SF = r->DE.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLC D"
       };
    (*instructions)[oc] = i;

    // RLC E
    oc = 1027;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->DE.bytes.low >> 7) & 0x01);
            r->DE.bytes.low = rol<uint8_t>(r->DE.bytes.low);
            r->AF.bytes.low.SF = r->DE.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLC E"
       };
    (*instructions)[oc] = i;

    // RLC H
    oc = 1028;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->HL.bytes.high >> 7) & 0x01);
            r->HL.bytes.high = rol<uint8_t>(r->HL.bytes.high);
            r->AF.bytes.low.SF = r->HL.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLC H"
       };
    (*instructions)[oc] = i;

    // RLC L
    oc = 1029;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->HL.bytes.low >> 7) & 0x01);
            r->HL.bytes.low = rol<uint8_t>(r->HL.bytes.low);
            r->AF.bytes.low.SF = r->HL.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLC L"
       };
    (*instructions)[oc] = i;

    // RLC (HL)
    oc = 1030;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = (*m)[r->HL.word];
            r->AF.bytes.low.CF = (bool)((hlMem >> 7) & 0x01);
            hlMem = rol<uint8_t>(hlMem);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            (*m)[r->HL.word] = hlMem;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RLC (HL)"
       };
    (*instructions)[oc] = i;

    // RLC A
    oc = 1031;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high >> 7) & 0x01);
            r->AF.bytes.high = rol<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.SF = r->AF.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->AF.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->AF.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RLC A"
       };
    (*instructions)[oc] = i;

    // RRC B
    oc = 1032;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->BC.bytes.high) & 0x01);
            r->BC.bytes.high = ror<uint8_t>(r->BC.bytes.high);
            r->AF.bytes.low.SF = r->BC.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRC B"
       };
    (*instructions)[oc] = i;

    // RRC C
    oc = 1033;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->BC.bytes.low) & 0x01);
            r->BC.bytes.low = ror<uint8_t>(r->BC.bytes.low);
            r->AF.bytes.low.SF = r->BC.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRC C"
       };
    (*instructions)[oc] = i;

    // RRC D
    oc = 1034;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->DE.bytes.high) & 0x01);
            r->DE.bytes.high = ror<uint8_t>(r->DE.bytes.high);
            r->AF.bytes.low.SF = r->DE.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRC D"
       };
    (*instructions)[oc] = i;

    // RRC E
    oc = 1035;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->DE.bytes.low) & 0x01);
            r->DE.bytes.low = ror<uint8_t>(r->DE.bytes.low);
            r->AF.bytes.low.SF = r->DE.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRC E"
       };
    (*instructions)[oc] = i;

    // RRC H
    oc = 1036;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->HL.bytes.high) & 0x01);
            r->HL.bytes.high = ror<uint8_t>(r->HL.bytes.high);
            r->AF.bytes.low.SF = r->HL.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRC H"
       };
    (*instructions)[oc] = i;

    // RRC L
    oc = 1037;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->HL.bytes.low) & 0x01);
            r->HL.bytes.low = ror<uint8_t>(r->HL.bytes.low);
            r->AF.bytes.low.SF = r->HL.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRC L"
       };
    (*instructions)[oc] = i;

    // RRC (HL)
    oc = 1038;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = (*m)[r->HL.word];
            r->AF.bytes.low.CF = (bool)((hlMem) & 0x01);
            hlMem = ror<uint8_t>(hlMem);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            (*m)[r->HL.word] = hlMem;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RRC (HL)"
       };
    (*instructions)[oc] = i;

    // RRC A
    oc = 1039;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((r->AF.bytes.high) & 0x01);
            r->AF.bytes.high = ror<uint8_t>(r->AF.bytes.high);
            r->AF.bytes.low.SF = r->AF.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->AF.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->AF.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RRC A"
       };
    (*instructions)[oc] = i;

    // RL B
    oc = 1040;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(r->BC.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->BC.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RL B"
       };
    (*instructions)[oc] = i;

    // RL C
    oc = 1041;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(r->BC.bytes.low, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->BC.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RL C"
       };
    (*instructions)[oc] = i;

    // RL D
    oc = 1042;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(r->DE.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->DE.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RL D"
       };
    (*instructions)[oc] = i;

    // RL E
    oc = 1043;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(r->DE.bytes.low, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->DE.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RL E"
       };
    (*instructions)[oc] = i;

    // RL H
    oc = 1044;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(r->HL.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->HL.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RL H"
       };
    (*instructions)[oc] = i;

    // RL L
    oc = 1045;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(r->HL.bytes.low, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->HL.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RL L"
       };
    (*instructions)[oc] = i;

    // RL (HL)
    oc = 1046;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = (*m)[r->HL.word];
            r->AF.bytes.low.CF = rolc<uint8_t>(hlMem, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            (*m)[r->HL.word] = hlMem;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RL (HL)"
       };
    (*instructions)[oc] = i;

    // RL A
    oc = 1047;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->AF.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->AF.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->AF.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RL A"
       };
    (*instructions)[oc] = i;

    // RR B
    oc = 1048;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(r->BC.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->BC.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RR B"
       };
    (*instructions)[oc] = i;

    // RR C
    oc = 1049;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(r->BC.bytes.low, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->BC.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->BC.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->BC.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RR C"
       };
    (*instructions)[oc] = i;

    // RR D
    oc = 1050;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(r->DE.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->DE.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RR D"
       };
    (*instructions)[oc] = i;

    // RR E
    oc = 1051;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(r->DE.bytes.low, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->DE.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->DE.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->DE.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RR E"
       };
    (*instructions)[oc] = i;

    // RR H
    oc = 1052;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(r->HL.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->HL.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RR H"
       };
    (*instructions)[oc] = i;

    // RR L
    oc = 1053;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(r->HL.bytes.low, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->HL.bytes.low >> 7;
            r->AF.bytes.low.ZF = r->HL.bytes.low == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->HL.bytes.low);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RR L"
       };
    (*instructions)[oc] = i;

    // RR (HL)
    oc = 1054;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = (*m)[r->HL.word];
            r->AF.bytes.low.CF = rorc<uint8_t>(hlMem, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            (*m)[r->HL.word] = hlMem;
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RR (HL)"
       };
    (*instructions)[oc] = i;

    // RR A
    oc = 1055;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = r->AF.bytes.high >> 7;
            r->AF.bytes.low.ZF = r->AF.bytes.high == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(r->AF.bytes.high);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RR A"
       };
    (*instructions)[oc] = i;

    // SLA B
    oc = 1056;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLA B"
       };
    (*instructions)[oc] = i;

    // SLA C
    oc = 1057;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLA C"
       };
    (*instructions)[oc] = i;

    // SLA D
    oc = 1058;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLA D"
       };
    (*instructions)[oc] = i;

    // SLA E
    oc = 1059;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLA E"
       };
    (*instructions)[oc] = i;

    // SLA H
    oc = 1060;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->HL.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLA H"
       };
    (*instructions)[oc] = i;

    // SLA L
    oc = 1061;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->HL.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLA L"
       };
    (*instructions)[oc] = i;

    // SLA (HL)
    oc = 1062;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla((*m)[r->HL.word], r);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SLA (HL)"
       };
    (*instructions)[oc] = i;

    // SLA A
    oc = 1063;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLA A"
       };
    (*instructions)[oc] = i;

    // SRA B
    oc = 1064;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra(r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRA B"
       };
    (*instructions)[oc] = i;

    // SRA C
    oc = 1065;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra(r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRA C"
       };
    (*instructions)[oc] = i;

    // SRA D
    oc = 1066;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra(r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRA D"
       };
    (*instructions)[oc] = i;

    // SRA E
    oc = 1067;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra(r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRA E"
       };
    (*instructions)[oc] = i;

    // SRA H
    oc = 1068;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra(r->HL.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRA H"
       };
    (*instructions)[oc] = i;

    // SRA L
    oc = 1069;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra(r->HL.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRA L"
       };
    (*instructions)[oc] = i;

    // SRA (HL)
    oc = 1070;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra((*m)[r->HL.word], r);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SRA (HL)"
       };
    (*instructions)[oc] = i;

    // SRA A
    oc = 1071;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sra(r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRA A"
       };
    (*instructions)[oc] = i;

    // SLL B
    oc = 1072;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->BC.bytes.high, r, true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLL B"
       };
    (*instructions)[oc] = i;

    // SLL C
    oc = 1073;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->BC.bytes.low, r, true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLL C"
       };
    (*instructions)[oc] = i;

    // SLL D
    oc = 1074;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->DE.bytes.high, r, true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLL D"
       };
    (*instructions)[oc] = i;

    // SLL E
    oc = 1075;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->DE.bytes.low, r, true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLL E"
       };
    (*instructions)[oc] = i;

    // SLL H
    oc = 1076;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->HL.bytes.high, r, true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLL H"
       };
    (*instructions)[oc] = i;

    // SLL L
    oc = 1077;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->HL.bytes.low, r, true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLL L"
       };
    (*instructions)[oc] = i;

    // SLL (HL)
    oc = 1078;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla((*m)[r->HL.word], r, true);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SLL (HL)"
       };
    (*instructions)[oc] = i;

    // SLL A
    oc = 1079;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            sla(r->AF.bytes.high, r, true);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SLL A"
       };
    (*instructions)[oc] = i;

    // SRL B
    oc = 1080;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl(r->BC.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRL B"
       };
    (*instructions)[oc] = i;

    // SRL C
    oc = 1081;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl(r->BC.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRL C"
       };
    (*instructions)[oc] = i;

    // SRL D
    oc = 1082;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl(r->DE.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRL D"
       };
    (*instructions)[oc] = i;

    // SRL E
    oc = 1083;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl(r->DE.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRL E"
       };
    (*instructions)[oc] = i;

    // SRL H
    oc = 1084;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl(r->HL.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRL H"
       };
    (*instructions)[oc] = i;

    // SRL L
    oc = 1085;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl(r->HL.bytes.low, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRL L"
       };
    (*instructions)[oc] = i;

    // SRL (HL)
    oc = 1086;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl((*m)[r->HL.word], r);
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SRL (HL)"
       };
    (*instructions)[oc] = i;

    // SRL A
    oc = 1087;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            srl(r->AF.bytes.high, r);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SRL A"
       };
    (*instructions)[oc] = i;

    // BIT 0,B
    oc = 1088;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 0,B"
       };
    (*instructions)[oc] = i;

    // BIT 0,C
    oc = 1089;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 0,C"
       };
    (*instructions)[oc] = i;

    // BIT 0,D
    oc = 1090;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 0,D"
       };
    (*instructions)[oc] = i;

    // BIT 0,E
    oc = 1091;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 0,E"
       };
    (*instructions)[oc] = i;

    // BIT 0,H
    oc = 1092;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 0,H"
       };
    (*instructions)[oc] = i;

    // BIT 0,L
    oc = 1093;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 0,L"
       };
    (*instructions)[oc] = i;

    // BIT 0,(HL)
    oc = 1094;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 0,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 0,A
    oc = 1095;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 0,A"
       };
    (*instructions)[oc] = i;

    // BIT 1,B
    oc = 1096;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 1,B"
       };
    (*instructions)[oc] = i;

    // BIT 1,C
    oc = 1097;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 1,C"
       };
    (*instructions)[oc] = i;

    // BIT 1,D
    oc = 1098;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 1,D"
       };
    (*instructions)[oc] = i;

    // BIT 1,E
    oc = 1099;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 1,E"
       };
    (*instructions)[oc] = i;

    // BIT 1,H
    oc = 1100;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 1,H"
       };
    (*instructions)[oc] = i;

    // BIT 1,L
    oc = 1101;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 1,L"
       };
    (*instructions)[oc] = i;

    // BIT 1,(HL)
    oc = 1102;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 1,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 1,A
    oc = 1103;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 1,A"
       };
    (*instructions)[oc] = i;

    // BIT 2,B
    oc = 1104;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 2,B"
       };
    (*instructions)[oc] = i;

    // BIT 2,C
    oc = 1105;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 2,C"
       };
    (*instructions)[oc] = i;

    // BIT 2,D
    oc = 1106;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 2,D"
       };
    (*instructions)[oc] = i;

    // BIT 2,E
    oc = 1107;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 2,E"
       };
    (*instructions)[oc] = i;

    // BIT 2,H
    oc = 1108;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 2,H"
       };
    (*instructions)[oc] = i;

    // BIT 2,L
    oc = 1109;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 2,L"
       };
    (*instructions)[oc] = i;

    // BIT 2,(HL)
    oc = 1110;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 2,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 2,A
    oc = 1111;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 2,A"
       };
    (*instructions)[oc] = i;

    // BIT 3,B
    oc = 1112;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 3,B"
       };
    (*instructions)[oc] = i;

    // BIT 3,C
    oc = 1113;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 3,C"
       };
    (*instructions)[oc] = i;

    // BIT 3,D
    oc = 1114;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 3,D"
       };
    (*instructions)[oc] = i;

    // BIT 3,E
    oc = 1115;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 3,E"
       };
    (*instructions)[oc] = i;

    // BIT 3,H
    oc = 1116;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 3,H"
       };
    (*instructions)[oc] = i;

    // BIT 3,L
    oc = 1117;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 3,L"
       };
    (*instructions)[oc] = i;

    // BIT 3,(HL)
    oc = 1118;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 3,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 3,A
    oc = 1119;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 3,A"
       };
    (*instructions)[oc] = i;

    // BIT 4,B
    oc = 1120;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 4,B"
       };
    (*instructions)[oc] = i;

    // BIT 4,C
    oc = 1121;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 4,C"
       };
    (*instructions)[oc] = i;

    // BIT 4,D
    oc = 1122;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 4,D"
       };
    (*instructions)[oc] = i;

    // BIT 4,E
    oc = 1123;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 4,E"
       };
    (*instructions)[oc] = i;

    // BIT 4,H
    oc = 1124;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 4,H"
       };
    (*instructions)[oc] = i;

    // BIT 4,L
    oc = 1125;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 4,L"
       };
    (*instructions)[oc] = i;

    // BIT 4,(HL)
    oc = 1126;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 4,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 4,A
    oc = 1127;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 4,A"
       };
    (*instructions)[oc] = i;

    // BIT 5,B
    oc = 1128;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 5,B"
       };
    (*instructions)[oc] = i;

    // BIT 5,C
    oc = 1129;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 5,C"
       };
    (*instructions)[oc] = i;

    // BIT 5,D
    oc = 1130;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 5,D"
       };
    (*instructions)[oc] = i;

    // BIT 5,E
    oc = 1131;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 5,E"
       };
    (*instructions)[oc] = i;

    // BIT 5,H
    oc = 1132;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 5,H"
       };
    (*instructions)[oc] = i;

    // BIT 5,L
    oc = 1133;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 5,L"
       };
    (*instructions)[oc] = i;

    // BIT 5,(HL)
    oc = 1134;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 5,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 5,A
    oc = 1135;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 5,A"
       };
    (*instructions)[oc] = i;

    // BIT 6,B
    oc = 1136;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 6,B"
       };
    (*instructions)[oc] = i;

    // BIT 6,C
    oc = 1137;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 6,C"
       };
    (*instructions)[oc] = i;

    // BIT 6,D
    oc = 1138;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 6,D"
       };
    (*instructions)[oc] = i;

    // BIT 6,E
    oc = 1139;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 6,E"
       };
    (*instructions)[oc] = i;

    // BIT 6,H
    oc = 1140;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 6,H"
       };
    (*instructions)[oc] = i;

    // BIT 6,L
    oc = 1141;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 6,L"
       };
    (*instructions)[oc] = i;

    // BIT 6,(HL)
    oc = 1142;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 6,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 6,A
    oc = 1143;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 6,A"
       };
    (*instructions)[oc] = i;

    // BIT 7,B
    oc = 1144;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.high & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 7,B"
       };
    (*instructions)[oc] = i;

    // BIT 7,C
    oc = 1145;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->BC.bytes.low & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 7,C"
       };
    (*instructions)[oc] = i;

    // BIT 7,D
    oc = 1146;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.high & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 7,D"
       };
    (*instructions)[oc] = i;

    // BIT 7,E
    oc = 1147;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->DE.bytes.low & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 7,E"
       };
    (*instructions)[oc] = i;

    // BIT 7,H
    oc = 1148;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.high & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 7,H"
       };
    (*instructions)[oc] = i;

    // BIT 7,L
    oc = 1149;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->HL.bytes.low & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 7,L"
       };
    (*instructions)[oc] = i;

    // BIT 7,(HL)
    oc = 1150;
    i = { 12, 12, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->HL.word]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        3, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 0, 0, 0, 0 },
        "BIT 7,(HL)"
       };
    (*instructions)[oc] = i;

    // BIT 7,A
    oc = 1151;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( r->AF.bytes.high & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "BIT 7,A"
       };
    (*instructions)[oc] = i;

    // RES 0,B
    oc = 1152;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 0,B"
       };
    (*instructions)[oc] = i;

    // RES 0,C
    oc = 1153;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 0,C"
       };
    (*instructions)[oc] = i;

    // RES 0,D
    oc = 1154;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 0,D"
       };
    (*instructions)[oc] = i;

    // RES 0,E
    oc = 1155;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 0,E"
       };
    (*instructions)[oc] = i;

    // RES 0,H
    oc = 1156;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 0,H"
       };
    (*instructions)[oc] = i;

    // RES 0,L
    oc = 1157;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 0,L"
       };
    (*instructions)[oc] = i;

    // RES 0,(HL)
    oc = 1158;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 0 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 0,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 0,A
    oc = 1159;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 0,A"
       };
    (*instructions)[oc] = i;

    // RES 1,B
    oc = 1160;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 1,B"
       };
    (*instructions)[oc] = i;

    // RES 1,C
    oc = 1161;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 1,C"
       };
    (*instructions)[oc] = i;

    // RES 1,D
    oc = 1162;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 1,D"
       };
    (*instructions)[oc] = i;

    // RES 1,E
    oc = 1163;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 1,E"
       };
    (*instructions)[oc] = i;

    // RES 1,H
    oc = 1164;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 1,H"
       };
    (*instructions)[oc] = i;

    // RES 1,L
    oc = 1165;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 1,L"
       };
    (*instructions)[oc] = i;

    // RES 1,(HL)
    oc = 1166;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 1 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 1,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 1,A
    oc = 1167;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 1,A"
       };
    (*instructions)[oc] = i;

    // RES 2,B
    oc = 1168;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 2,B"
       };
    (*instructions)[oc] = i;

    // RES 2,C
    oc = 1169;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 2,C"
       };
    (*instructions)[oc] = i;

    // RES 2,D
    oc = 1170;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 2,D"
       };
    (*instructions)[oc] = i;

    // RES 2,E
    oc = 1171;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 2,E"
       };
    (*instructions)[oc] = i;

    // RES 2,H
    oc = 1172;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 2,H"
       };
    (*instructions)[oc] = i;

    // RES 2,L
    oc = 1173;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 2,L"
       };
    (*instructions)[oc] = i;

    // RES 2,(HL)
    oc = 1174;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 2 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 2,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 2,A
    oc = 1175;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 2,A"
       };
    (*instructions)[oc] = i;

    // RES 3,B
    oc = 1176;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 3,B"
       };
    (*instructions)[oc] = i;

    // RES 3,C
    oc = 1177;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 3,C"
       };
    (*instructions)[oc] = i;

    // RES 3,D
    oc = 1178;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 3,D"
       };
    (*instructions)[oc] = i;

    // RES 3,E
    oc = 1179;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 3,E"
       };
    (*instructions)[oc] = i;

    // RES 3,H
    oc = 1180;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 3,H"
       };
    (*instructions)[oc] = i;

    // RES 3,L
    oc = 1181;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 3,L"
       };
    (*instructions)[oc] = i;

    // RES 3,(HL)
    oc = 1182;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 3 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 3,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 3,A
    oc = 1183;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 3,A"
       };
    (*instructions)[oc] = i;

    // RES 4,B
    oc = 1184;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 4,B"
       };
    (*instructions)[oc] = i;

    // RES 4,C
    oc = 1185;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 4,C"
       };
    (*instructions)[oc] = i;

    // RES 4,D
    oc = 1186;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 4,D"
       };
    (*instructions)[oc] = i;

    // RES 4,E
    oc = 1187;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 4,E"
       };
    (*instructions)[oc] = i;

    // RES 4,H
    oc = 1188;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 4,H"
       };
    (*instructions)[oc] = i;

    // RES 4,L
    oc = 1189;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 4,L"
       };
    (*instructions)[oc] = i;

    // RES 4,(HL)
    oc = 1190;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 4 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 4,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 4,A
    oc = 1191;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 4,A"
       };
    (*instructions)[oc] = i;

    // RES 5,B
    oc = 1192;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 5,B"
       };
    (*instructions)[oc] = i;

    // RES 5,C
    oc = 1193;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 5,C"
       };
    (*instructions)[oc] = i;

    // RES 5,D
    oc = 1194;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 5,D"
       };
    (*instructions)[oc] = i;

    // RES 5,E
    oc = 1195;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 5,E"
       };
    (*instructions)[oc] = i;

    // RES 5,H
    oc = 1196;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 5,H"
       };
    (*instructions)[oc] = i;

    // RES 5,L
    oc = 1197;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 5,L"
       };
    (*instructions)[oc] = i;

    // RES 5,(HL)
    oc = 1198;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 5 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 5,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 5,A
    oc = 1199;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 5,A"
       };
    (*instructions)[oc] = i;

    // RES 6,B
    oc = 1200;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 6,B"
       };
    (*instructions)[oc] = i;

    // RES 6,C
    oc = 1201;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 6,C"
       };
    (*instructions)[oc] = i;

    // RES 6,D
    oc = 1202;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 6,D"
       };
    (*instructions)[oc] = i;

    // RES 6,E
    oc = 1203;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 6,E"
       };
    (*instructions)[oc] = i;

    // RES 6,H
    oc = 1204;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 6,H"
       };
    (*instructions)[oc] = i;

    // RES 6,L
    oc = 1205;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 6,L"
       };
    (*instructions)[oc] = i;

    // RES 6,(HL)
    oc = 1206;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 6 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 6,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 6,A
    oc = 1207;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 6,A"
       };
    (*instructions)[oc] = i;

    // RES 7,B
    oc = 1208;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high &= ~( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 7,B"
       };
    (*instructions)[oc] = i;

    // RES 7,C
    oc = 1209;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low &= ~( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 7,C"
       };
    (*instructions)[oc] = i;

    // RES 7,D
    oc = 1210;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high &= ~( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 7,D"
       };
    (*instructions)[oc] = i;

    // RES 7,E
    oc = 1211;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low &= ~( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 7,E"
       };
    (*instructions)[oc] = i;

    // RES 7,H
    oc = 1212;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high &= ~( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 7,H"
       };
    (*instructions)[oc] = i;

    // RES 7,L
    oc = 1213;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low &= ~( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 7,L"
       };
    (*instructions)[oc] = i;

    // RES 7,(HL)
    oc = 1214;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] &= ~( 0x1 << 7 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "RES 7,(HL)"
       };
    (*instructions)[oc] = i;

    // RES 7,A
    oc = 1215;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high &= ~( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "RES 7,A"
       };
    (*instructions)[oc] = i;

    // SET 0,B
    oc = 1216;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 0,B"
       };
    (*instructions)[oc] = i;

    // SET 0,C
    oc = 1217;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 0,C"
       };
    (*instructions)[oc] = i;

    // SET 0,D
    oc = 1218;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 0,D"
       };
    (*instructions)[oc] = i;

    // SET 0,E
    oc = 1219;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 0,E"
       };
    (*instructions)[oc] = i;

    // SET 0,H
    oc = 1220;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 0,H"
       };
    (*instructions)[oc] = i;

    // SET 0,L
    oc = 1221;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 0,L"
       };
    (*instructions)[oc] = i;

    // SET 0,(HL)
    oc = 1222;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 0 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 0,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 0,A
    oc = 1223;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 0 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 0,A"
       };
    (*instructions)[oc] = i;

    // SET 1,B
    oc = 1224;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 1,B"
       };
    (*instructions)[oc] = i;

    // SET 1,C
    oc = 1225;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 1,C"
       };
    (*instructions)[oc] = i;

    // SET 1,D
    oc = 1226;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 1,D"
       };
    (*instructions)[oc] = i;

    // SET 1,E
    oc = 1227;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 1,E"
       };
    (*instructions)[oc] = i;

    // SET 1,H
    oc = 1228;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 1,H"
       };
    (*instructions)[oc] = i;

    // SET 1,L
    oc = 1229;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 1,L"
       };
    (*instructions)[oc] = i;

    // SET 1,(HL)
    oc = 1230;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 1 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 1,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 1,A
    oc = 1231;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 1 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 1,A"
       };
    (*instructions)[oc] = i;
    
    // SET 2,B
    oc = 1232;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 2,B"
       };
    (*instructions)[oc] = i;

    // SET 2,C
    oc = 1233;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 2,C"
       };
    (*instructions)[oc] = i;

    // SET 2,D
    oc = 1234;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 2,D"
       };
    (*instructions)[oc] = i;

    // SET 2,E
    oc = 1235;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 2,E"
       };
    (*instructions)[oc] = i;

    // SET 2,H
    oc = 1236;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 2,H"
       };
    (*instructions)[oc] = i;

    // SET 2,L
    oc = 1237;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 2,L"
       };
    (*instructions)[oc] = i;

    // SET 2,(HL)
    oc = 1238;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 2 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 2,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 2,A
    oc = 1239;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 2 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 2,A"
       };
    (*instructions)[oc] = i;

    // SET 3,B
    oc = 1240;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 3,B"
       };
    (*instructions)[oc] = i;

    // SET 3,C
    oc = 1241;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 3,C"
       };
    (*instructions)[oc] = i;

    // SET 3,D
    oc = 1242;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 3,D"
       };
    (*instructions)[oc] = i;

    // SET 3,E
    oc = 1243;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 3,E"
       };
    (*instructions)[oc] = i;

    // SET 3,H
    oc = 1244;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 3,H"
       };
    (*instructions)[oc] = i;

    // SET 3,L
    oc = 1245;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 3,L"
       };
    (*instructions)[oc] = i;

    // SET 3,(HL)
    oc = 1246;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 3 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 3,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 3,A
    oc = 1247;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 3 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 3,A"
       };
    (*instructions)[oc] = i;

    // SET 4,B
    oc = 1248;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 4,B"
       };
    (*instructions)[oc] = i;

    // SET 4,C
    oc = 1249;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 4,C"
       };
    (*instructions)[oc] = i;

    // SET 4,D
    oc = 1250;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 4,D"
       };
    (*instructions)[oc] = i;

    // SET 4,E
    oc = 1251;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 4,E"
       };
    (*instructions)[oc] = i;

    // SET 4,H
    oc = 1252;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 4,H"
       };
    (*instructions)[oc] = i;

    // SET 4,L
    oc = 1253;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 4,L"
       };
    (*instructions)[oc] = i;

    // SET 4,(HL)
    oc = 1254;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 4 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 4,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 4,A
    oc = 1255;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 4 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 4,A"
       };
    (*instructions)[oc] = i;

    // SET 5,B
    oc = 1256;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 5,B"
       };
    (*instructions)[oc] = i;

    // SET 5,C
    oc = 1257;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 5,C"
       };
    (*instructions)[oc] = i;

    // SET 5,D
    oc = 1258;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 5,D"
       };
    (*instructions)[oc] = i;

    // SET 5,E
    oc = 1259;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 5,E"
       };
    (*instructions)[oc] = i;

    // SET 5,H
    oc = 1260;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 5,H"
       };
    (*instructions)[oc] = i;

    // SET 5,L
    oc = 1261;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 5,L"
       };
    (*instructions)[oc] = i;

    // SET 5,(HL)
    oc = 1262;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 5 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 5,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 5,A
    oc = 1263;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 5 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 5,A"
       };
    (*instructions)[oc] = i;

    // SET 6,B
    oc = 1264;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 6,B"
       };
    (*instructions)[oc] = i;

    // SET 6,C
    oc = 1265;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 6,C"
       };
    (*instructions)[oc] = i;

    // SET 6,D
    oc = 1266;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 6,D"
       };
    (*instructions)[oc] = i;

    // SET 6,E
    oc = 1267;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 6,E"
       };
    (*instructions)[oc] = i;

    // SET 6,H
    oc = 1268;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 6,H"
       };
    (*instructions)[oc] = i;

    // SET 6,L
    oc = 1269;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 6,L"
       };
    (*instructions)[oc] = i;

    // SET 6,(HL)
    oc = 1270;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 6 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 6,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 6,A
    oc = 1271;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 6 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 6,A"
       };
    (*instructions)[oc] = i;

    // SET 7,B
    oc = 1272;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high |= ( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 7,B"
       };
    (*instructions)[oc] = i;

    // SET 7,C
    oc = 1273;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.low |= ( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 7,C"
       };
    (*instructions)[oc] = i;

    // SET 7,D
    oc = 1274;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.high |= ( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 7,D"
       };
    (*instructions)[oc] = i;

    // SET 7,E
    oc = 1275;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.bytes.low |= ( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 7,E"
       };
    (*instructions)[oc] = i;

    // SET 7,H
    oc = 1276;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.high |= ( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 7,H"
       };
    (*instructions)[oc] = i;

    // SET 7,L
    oc = 1277;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.bytes.low |= ( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 7,L"
       };
    (*instructions)[oc] = i;

    // SET 7,(HL)
    oc = 1278;
    i = { 15, 15, 0, INST{
            Z80Registers* r = z->getRegisters();
            (*m)[r->HL.word] |= ( 0x1 << 7 );
        },
        4, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 4, 3, 0, 0, 0 },
        "SET 7,(HL)"
       };
    (*instructions)[oc] = i;

    // SET 7,A
    oc = 1279;
    i = { 8, 8, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.high |= ( 0x1 << 7 );
        },
        2, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 0, 0, 0, 0, 0 },
        "SET 7,A"
       };
    (*instructions)[oc] = i;

    /* DDCB prefix instructions */

    // RLC (IX+d)->B
    oc = 2304;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RLC (IX+d)->C
    oc = 2305;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RLC (IX+d)->D
    oc = 2306;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RLC (IX+d)->E
    oc = 2307;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RLC (IX+d)->H
    oc = 2308;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RLC (IX+d)->L
    oc = 2309;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RLC (IX+d)
    oc = 2310;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = (*m)[r->IX.word + ((int8_t)d[0])];
            r->AF.bytes.low.CF = (bool)((hlMem >> 7) & 0x01);
            hlMem = rol<uint8_t>(hlMem);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            (*m)[r->IX.word + ((int8_t)d[0])] = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)"
       };
    (*instructions)[oc] = i;

    // RLC (IX+d)->A
    oc = 2311;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)->B
    oc = 2312;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)->C
    oc = 2313;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)->D
    oc = 2314;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)->E
    oc = 2315;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)->H
    oc = 2316;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)->L
    oc = 2317;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)
    oc = 2318;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = ((*m)[r->IX.word + ((int8_t)d[0])]);
            r->AF.bytes.low.CF = (bool)((hlMem) & 0x01);
            hlMem = ror<uint8_t>(hlMem);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)"
       };
    (*instructions)[oc] = i;

    // RRC (IX+d)->A
    oc = 2319;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IX.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)->B
    oc = 2320;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)->C
    oc = 2321;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)->D
    oc = 2322;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)->E
    oc = 2323;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)->H
    oc = 2324;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)->L
    oc = 2325;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)
    oc = 2326;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = ((*m)[r->IX.word + ((int8_t)d[0])]);
            r->AF.bytes.low.CF = rolc<uint8_t>(hlMem, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)"
       };
    (*instructions)[oc] = i;

    // RL (IX+d)->A
    oc = 2327;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)->B
    oc = 2328;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)->C
    oc = 2329;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)->D
    oc = 2330;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)->E
    oc = 2331;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)->H
    oc = 2332;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)->L
    oc = 2333;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)
    oc = 2334;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = ((*m)[r->IX.word + ((int8_t)d[0])]);
            r->AF.bytes.low.CF = rorc<uint8_t>(hlMem, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            ((*m)[r->IX.word + ((int8_t)d[0])]) = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)"
       };
    (*instructions)[oc] = i;

    // RR (IX+d)->A
    oc = 2335;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IX.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IX.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IX.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IX.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)->B
    oc = 2336;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)->C
    oc = 2337;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)->D
    oc = 2338;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)->E
    oc = 2339;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)->H
    oc = 2340;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)->L
    oc = 2341;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)
    oc = 2342;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)"
       };
    (*instructions)[oc] = i;

    // SLA (IX+d)->A
    oc = 2343;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)->B
    oc = 2344;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)->C
    oc = 2345;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)->D
    oc = 2346;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)->E
    oc = 2347;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)->H
    oc = 2348;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)->L
    oc = 2349;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)
    oc = 2350;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)"
       };
    (*instructions)[oc] = i;

    // SRA (IX+d)->A
    oc = 2351;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)->B
    oc = 2352;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)->C
    oc = 2353;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)->D
    oc = 2354;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)->E
    oc = 2355;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)->H
    oc = 2356;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)->L
    oc = 2357;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)
    oc = 2358;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)"
       };
    (*instructions)[oc] = i;

    // SLL (IX+d)->A
    oc = 2359;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IX.word + ((int8_t)d[0])]), r, true);
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)->B
    oc = 2360;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)->C
    oc = 2361;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)->D
    oc = 2362;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)->E
    oc = 2363;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)->H
    oc = 2364;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)->L
    oc = 2365;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)
    oc = 2366;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)"
       };
    (*instructions)[oc] = i;

    // SRL (IX+d)->A
    oc = 2367;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IX.word + ((int8_t)d[0])]), r);
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IX+d)->A"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2368;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2369;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2370;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2371;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2372;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2373;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2374;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IX+d)
    oc = 2375;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2376;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2377;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2378;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2379;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2380;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2381;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2382;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IX+d)
    oc = 2383;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2384;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2385;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2386;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2387;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2388;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2389;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2390;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IX+d)
    oc = 2391;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2392;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2393;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2394;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2395;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2396;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2397;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2398;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IX+d)
    oc = 2399;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2400;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2401;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2402;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)(((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2403;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2404;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2405;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2406;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IX+d)
    oc = 2407;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2408;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2409;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2410;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2411;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2412;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2413;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2414;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IX+d)
    oc = 2415;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2416;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2417;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2418;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2419;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2420;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2421;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2422;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IX+d)
    oc = 2423;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2424;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2425;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2426;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2427;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2428;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2429;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2430;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IX+d)
    oc = 2431;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IX.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = ! (r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)->B
    oc = 2432;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)->C
    oc = 2433;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)->D
    oc = 2434;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)->E
    oc = 2435;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)->H
    oc = 2436;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)->L
    oc = 2437;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)
    oc = 2438;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 0,(IX+d)->A
    oc = 2439;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)->B
    oc = 2440;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)->C
    oc = 2441;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)->D
    oc = 2442;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)->E
    oc = 2443;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)->H
    oc = 2444;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)->L
    oc = 2445;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)
    oc = 2446;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 1,(IX+d)->A
    oc = 2447;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)->B
    oc = 2448;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)->C
    oc = 2449;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)->D
    oc = 2450;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)->E
    oc = 2451;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)->H
    oc = 2452;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)->L
    oc = 2453;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)
    oc = 2454;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 2,(IX+d)->A
    oc = 2455;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)->B
    oc = 2456;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)->C
    oc = 2457;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)->D
    oc = 2458;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)->E
    oc = 2459;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)->H
    oc = 2460;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)->L
    oc = 2461;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)
    oc = 2462;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 3,(IX+d)->A
    oc = 2463;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)->B
    oc = 2464;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)->C
    oc = 2465;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)->D
    oc = 2466;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)->E
    oc = 2467;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)->H
    oc = 2468;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)->L
    oc = 2469;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)
    oc = 2470;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 4,(IX+d)->A
    oc = 2471;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)->B
    oc = 2472;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)->C
    oc = 2473;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)->D
    oc = 2474;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)->E
    oc = 2475;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)->H
    oc = 2476;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)->L
    oc = 2477;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)
    oc = 2478;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 5,(IX+d)->A
    oc = 2479;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)->B
    oc = 2480;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)->C
    oc = 2481;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)->D
    oc = 2482;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)->E
    oc = 2483;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)->H
    oc = 2484;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)->L
    oc = 2485;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)
    oc = 2486;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 6,(IX+d)->A
    oc = 2487;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)->B
    oc = 2488;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)->C
    oc = 2489;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)->D
    oc = 2490;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)->E
    oc = 2491;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)->H
    oc = 2492;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)->L
    oc = 2493;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)
    oc = 2494;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // RES 7,(IX+d)->A
    oc = 2495;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)->B
    oc = 2496;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)->C
    oc = 2497;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)->D
    oc = 2498;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)->E
    oc = 2499;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)->H
    oc = 2500;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)->L
    oc = 2501;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)
    oc = 2502;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 0,(IX+d)->A
    oc = 2503;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)->B
    oc = 2504;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)->C
    oc = 2505;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)->D
    oc = 2506;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)->E
    oc = 2507;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)->H
    oc = 2508;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)->L
    oc = 2509;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)
    oc = 2510;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 1,(IX+d)->A
    oc = 2511;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IX+d)->A"
       };
    (*instructions)[oc] = i;
    
    // SET 2,(IX+d)->B
    oc = 2512;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 2,(IX+d)->C
    oc = 2513;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 2,(IX+d)->D
    oc = 2514;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 2,(IX+d)->E
    oc = 2515;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 2,(IX+d)->H
    oc = 2516;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 2,(IX+d)->L
    oc = 2517;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 2,(IX+d)
    oc = 2518;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 2,(IX+d)->A
    oc = 2519;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)->B
    oc = 2520;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)->C
    oc = 2521;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)->D
    oc = 2522;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)->E
    oc = 2523;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)->H
    oc = 2524;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)->L
    oc = 2525;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)
    oc = 2526;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 3,(IX+d)->A
    oc = 2527;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)->B
    oc = 2528;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)->C
    oc = 2529;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)->D
    oc = 2530;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)->E
    oc = 2531;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)->H
    oc = 2532;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)->L
    oc = 2533;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)
    oc = 2534;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 4,(IX+d)->A
    oc = 2535;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)->B
    oc = 2536;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)->C
    oc = 2537;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)->D
    oc = 2538;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)->E
    oc = 2539;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)->H
    oc = 2540;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)->L
    oc = 2541;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)
    oc = 2542;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 5,(IX+d)->A
    oc = 2543;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)->B
    oc = 2544;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)->C
    oc = 2545;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)->D
    oc = 2546;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)->E
    oc = 2547;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)->H
    oc = 2548;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)->L
    oc = 2549;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)
    oc = 2550;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 6,(IX+d)->A
    oc = 2551;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)->B
    oc = 2552;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->BC.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)->C
    oc = 2553;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->BC.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)->D
    oc = 2554;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->DE.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)->E
    oc = 2555;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->DE.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)->H
    oc = 2556;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->HL.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)->L
    oc = 2557;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->HL.bytes.low = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)
    oc = 2558;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)"
       };
    (*instructions)[oc] = i;

    // SET 7,(IX+d)->A
    oc = 2559;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IX.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->AF.bytes.high = ((*m)[r->IX.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IX+d)->A"
       };
    (*instructions)[oc] = i;

    /* FDCB prefix instructions */

    // RLC (IY+d)->B
    oc = 2560;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RLC (IY+d)->C
    oc = 2561;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RLC (IY+d)->D
    oc = 2562;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RLC (IY+d)->E
    oc = 2563;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RLC (IY+d)->H
    oc = 2564;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RLC (IY+d)->L
    oc = 2565;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RLC (IY+d)
    oc = 2566;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = (*m)[r->IY.word + ((int8_t)d[0])];
            r->AF.bytes.low.CF = (bool)((hlMem >> 7) & 0x01);
            hlMem = rol<uint8_t>(hlMem);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            (*m)[r->IY.word + ((int8_t)d[0])] = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)"
       };
    (*instructions)[oc] = i;

    // RLC (IY+d)->A
    oc = 2567;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])]) >> 7) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = rol<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RLC (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)->B
    oc = 2568;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)->C
    oc = 2569;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)->D
    oc = 2570;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)->E
    oc = 2571;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)->H
    oc = 2572;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)->L
    oc = 2573;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)
    oc = 2574;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = ((*m)[r->IY.word + ((int8_t)d[0])]);
            r->AF.bytes.low.CF = (bool)((hlMem) & 0x01);
            hlMem = ror<uint8_t>(hlMem);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)"
       };
    (*instructions)[oc] = i;

    // RRC (IY+d)->A
    oc = 2575;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = (bool)((((*m)[r->IY.word + ((int8_t)d[0])])) & 0x01);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = ror<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RRC (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)->B
    oc = 2576;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)->C
    oc = 2577;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)->D
    oc = 2578;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)->E
    oc = 2579;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)->H
    oc = 2580;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)->L
    oc = 2581;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)
    oc = 2582;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = ((*m)[r->IY.word + ((int8_t)d[0])]);
            r->AF.bytes.low.CF = rolc<uint8_t>(hlMem, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)"
       };
    (*instructions)[oc] = i;

    // RL (IY+d)->A
    oc = 2583;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RL (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)->B
    oc = 2584;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)->C
    oc = 2585;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)->D
    oc = 2586;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)->E
    oc = 2587;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)->H
    oc = 2588;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)->L
    oc = 2589;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)
    oc = 2590;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            uint8_t hlMem = ((*m)[r->IY.word + ((int8_t)d[0])]);
            r->AF.bytes.low.CF = rorc<uint8_t>(hlMem, r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = hlMem >> 7;
            r->AF.bytes.low.ZF = hlMem == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(hlMem);
            ((*m)[r->IY.word + ((int8_t)d[0])]) = hlMem;
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)"
       };
    (*instructions)[oc] = i;

    // RR (IY+d)->A
    oc = 2591;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc<uint8_t>(((*m)[r->IY.word + ((int8_t)d[0])]), r->AF.bytes.low.CF);
            r->AF.bytes.low.SF = ((*m)[r->IY.word + ((int8_t)d[0])]) >> 7;
            r->AF.bytes.low.ZF = ((*m)[r->IY.word + ((int8_t)d[0])]) == 0;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.PF = hasEvenParity(((*m)[r->IY.word + ((int8_t)d[0])]));
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RR (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)->B
    oc = 2592;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)->C
    oc = 2593;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)->D
    oc = 2594;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)->E
    oc = 2595;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)->H
    oc = 2596;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)->L
    oc = 2597;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)
    oc = 2598;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)"
       };
    (*instructions)[oc] = i;

    // SLA (IY+d)->A
    oc = 2599;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLA (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)->B
    oc = 2600;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)->C
    oc = 2601;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)->D
    oc = 2602;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)->E
    oc = 2603;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)->H
    oc = 2604;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)->L
    oc = 2605;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)
    oc = 2606;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)"
       };
    (*instructions)[oc] = i;

    // SRA (IY+d)->A
    oc = 2607;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sra(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRA (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)->B
    oc = 2608;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)->C
    oc = 2609;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)->D
    oc = 2610;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)->E
    oc = 2611;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)->H
    oc = 2612;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)->L
    oc = 2613;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)
    oc = 2614;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)"
       };
    (*instructions)[oc] = i;

    // SLL (IY+d)->A
    oc = 2615;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            sla(((*m)[r->IY.word + ((int8_t)d[0])]), r, true);
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SLL (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)->B
    oc = 2616;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)->C
    oc = 2617;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)->D
    oc = 2618;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)->E
    oc = 2619;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)->H
    oc = 2620;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)->L
    oc = 2621;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)
    oc = 2622;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)"
       };
    (*instructions)[oc] = i;

    // SRL (IY+d)->A
    oc = 2623;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            srl(((*m)[r->IY.word + ((int8_t)d[0])]), r);
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SRL (IY+d)->A"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2624;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2625;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2626;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2627;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2628;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2629;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2630;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 0,(IY+d)
    oc = 2631;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 0) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2632;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2633;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2634;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2635;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2636;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2637;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2638;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 1,(IY+d)
    oc = 2639;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 1) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2640;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2641;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2642;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2643;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2644;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2645;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2646;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 2,(IY+d)
    oc = 2647;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 2) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2648;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2649;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2650;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2651;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2652;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2653;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2654;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 3,(IY+d)
    oc = 2655;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 3) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2656;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2657;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2658;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)(((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2659;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2660;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2661;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2662;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 4,(IY+d)
    oc = 2663;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 4) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2664;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2665;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2666;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2667;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2668;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2669;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2670;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 5,(IY+d)
    oc = 2671;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 5) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2672;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2673;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2674;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2675;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2676;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2677;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2678;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 6,(IY+d)
    oc = 2679;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 6) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = false;
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2680;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2681;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2682;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2683;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2684;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2685;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2686;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // BIT 7,(IY+d)
    oc = 2687;
    i = { 20, 20, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.ZF = !((bool)( ((*m)[r->IY.word + ((int8_t)d[0])]) & (0x1 << 7) ));
            r->AF.bytes.low.HF = true;
            r->AF.bytes.low.NF = false;
            r->AF.bytes.low.PF = r->AF.bytes.low.ZF;
            r->AF.bytes.low.SF = !(r->AF.bytes.low.ZF);
        },
        5, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::UNUSED, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 0, 0 },
        "BIT 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)->B
    oc = 2688;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)->C
    oc = 2689;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)->D
    oc = 2690;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)->E
    oc = 2691;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)->H
    oc = 2692;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)->L
    oc = 2693;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)
    oc = 2694;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 0,(IY+d)->A
    oc = 2695;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 0 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 0,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)->B
    oc = 2696;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)->C
    oc = 2697;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)->D
    oc = 2698;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)->E
    oc = 2699;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)->H
    oc = 2700;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)->L
    oc = 2701;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)
    oc = 2702;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 1,(IY+d)->A
    oc = 2703;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 1 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 1,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)->B
    oc = 2704;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)->C
    oc = 2705;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)->D
    oc = 2706;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)->E
    oc = 2707;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)->H
    oc = 2708;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)->L
    oc = 2709;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)
    oc = 2710;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 2,(IY+d)->A
    oc = 2711;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 2 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 2,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)->B
    oc = 2712;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)->C
    oc = 2713;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)->D
    oc = 2714;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)->E
    oc = 2715;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)->H
    oc = 2716;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)->L
    oc = 2717;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)
    oc = 2718;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 3,(IY+d)->A
    oc = 2719;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 3 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 3,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)->B
    oc = 2720;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)->C
    oc = 2721;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)->D
    oc = 2722;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)->E
    oc = 2723;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)->H
    oc = 2724;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)->L
    oc = 2725;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)
    oc = 2726;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 4,(IY+d)->A
    oc = 2727;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 4 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 4,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)->B
    oc = 2728;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)->C
    oc = 2729;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)->D
    oc = 2730;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)->E
    oc = 2731;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)->H
    oc = 2732;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)->L
    oc = 2733;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)
    oc = 2734;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 5,(IY+d)->A
    oc = 2735;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 5 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 5,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)->B
    oc = 2736;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)->C
    oc = 2737;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)->D
    oc = 2738;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)->E
    oc = 2739;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)->H
    oc = 2740;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)->L
    oc = 2741;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)
    oc = 2742;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 6,(IY+d)->A
    oc = 2743;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 6 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 6,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)->B
    oc = 2744;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)->C
    oc = 2745;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)->D
    oc = 2746;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)->E
    oc = 2747;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)->H
    oc = 2748;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)->L
    oc = 2749;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)
    oc = 2750;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // RES 7,(IY+d)->A
    oc = 2751;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) &= ~( 0x1 << 7 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "RES 7,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)->B
    oc = 2752;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)->C
    oc = 2753;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)->D
    oc = 2754;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)->E
    oc = 2755;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)->H
    oc = 2756;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)->L
    oc = 2757;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)
    oc = 2758;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 0,(IY+d)->A
    oc = 2759;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 0 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 0,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)->B
    oc = 2760;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)->C
    oc = 2761;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)->D
    oc = 2762;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)->E
    oc = 2763;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)->H
    oc = 2764;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)->L
    oc = 2765;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)
    oc = 2766;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 1,(IY+d)->A
    oc = 2767;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 1 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 1,(IY+d)->A"
       };
    (*instructions)[oc] = i;
    
    // SET 2,(IY+d)->B
    oc = 2768;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 2,(IY+d)->C
    oc = 2769;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 2,(IY+d)->D
    oc = 2770;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 2,(IY+d)->E
    oc = 2771;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 2,(IY+d)->H
    oc = 2772;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 2,(IY+d)->L
    oc = 2773;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 2,(IY+d)
    oc = 2774;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 2,(IY+d)->A
    oc = 2775;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 2 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 2,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)->B
    oc = 2776;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)->C
    oc = 2777;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)->D
    oc = 2778;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)->E
    oc = 2779;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)->H
    oc = 2780;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)->L
    oc = 2781;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)
    oc = 2782;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 3,(IY+d)->A
    oc = 2783;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 3 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 3,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)->B
    oc = 2784;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)->C
    oc = 2785;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)->D
    oc = 2786;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)->E
    oc = 2787;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)->H
    oc = 2788;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)->L
    oc = 2789;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)
    oc = 2790;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 4,(IY+d)->A
    oc = 2791;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 4 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 4,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)->B
    oc = 2792;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)->C
    oc = 2793;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)->D
    oc = 2794;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)->E
    oc = 2795;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)->H
    oc = 2796;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)->L
    oc = 2797;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)
    oc = 2798;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 5,(IY+d)->A
    oc = 2799;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 5 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 5,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)->B
    oc = 2800;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)->C
    oc = 2801;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)->D
    oc = 2802;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)->E
    oc = 2803;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)->H
    oc = 2804;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)->L
    oc = 2805;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)
    oc = 2806;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 6,(IY+d)->A
    oc = 2807;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 6 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 6,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)->B
    oc = 2808;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->BC.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)->B"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)->C
    oc = 2809;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->BC.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)->C"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)->D
    oc = 2810;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->DE.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)->D"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)->E
    oc = 2811;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->DE.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)->E"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)->H
    oc = 2812;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->HL.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)->H"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)->L
    oc = 2813;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->HL.bytes.low = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)->L"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)
    oc = 2814;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)"
       };
    (*instructions)[oc] = i;

    // SET 7,(IY+d)->A
    oc = 2815;
    i = { 23, 23, 1, INST{
            Z80Registers* r = z->getRegisters();
            ((*m)[r->IY.word + ((int8_t)d[0])]) |= ( 0x1 << 7 );
            r->AF.bytes.high = ((*m)[r->IY.word + ((int8_t)d[0])]);
        },
        6, { MachineCycleType::M1R, MachineCycleType::M1R, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MRD, MachineCycleType::MWR, MachineCycleType::UNUSED },
        { 4, 4, 3, 5, 4, 3, 0 },
        "SET 7,(IY+d)->A"
       };
    (*instructions)[oc] = i;

    return instructions;
}