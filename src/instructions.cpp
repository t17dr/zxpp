#include "instructions.h"

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

    // DJNZ
    oc = {0,0,0x0010};
    i = { 8, 13, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->BC.bytes.high = add<uint8_t>(r->BC.bytes.high, -1, r, 0);
            if (r->BC.bytes.high != 0)
            {
                r->PC += d[0];
            }
        }
    };
    instructions[oc] = i;

    // LD DE,nn
    oc = {0,0,0x0011};
    i = { 10, 10, 2, INST{ z->getRegisters()->DE.word = CREATE_WORD(d[0], d[1]); } };
    instructions[oc] = i;

    // LD (DE),A
    oc = {0,0,0x0012};
    i = { 7, 7, 0, INST{
            (*m)[z->getRegisters()->DE.word] = z->getRegisters()->AF.bytes.high;
        }
    };
    instructions[oc] = i;

    // INC DE
    oc = {0,0,0x0013};
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, 1, r, INC16);
        }
    };
    instructions[oc] = i;

    // INC D
    oc = {0,0,0x0014};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x7F) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // DEC D
    oc = {0,0,0x0015};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.high == 0x80) ? true : false;
            r->DE.bytes.high = add<uint8_t>(r->DE.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        }
    };
    instructions[oc] = i;

    // LD D,n
    oc = {0,0,0x0016};
    i = { 7, 7, 1, INST{ z->getRegisters()->DE.bytes.high = d[0]; } };
    instructions[oc] = i;

    // RLA
    oc = {0,0,0x0017};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rolc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // JR d
    oc = {0,0,0x0018};
    i = { 7, 12, 1, INST{
            Z80Registers* r = z->getRegisters();
            r->PC += d[0];
        }
    };
    instructions[oc] = i;

    // ADD HL,DE
    oc = {0,0,0x0019};
    i = { 11, 11, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add(r->HL.word, r->DE.word, r, ADD16);
            setUndocumentedFlags(r->HL.word, r);
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // LD A,(DE)
    oc = {0,0,0x001A};
    i = { 7, 7, 1, INST{
            z->getRegisters()->AF.bytes.high = (*m)[z->getRegisters()->DE.word];
        }
    };
    instructions[oc] = i;

    // DEC DE
    oc = {0,0,0x001B};
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->DE.word = add<uint16_t>(r->DE.word, -1, r, DEC16);
        }
    };
    instructions[oc] = i;

    // INC E
    oc = {0,0,0x001C};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x7F) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // DEC E
    oc = {0,0,0x001D};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->DE.bytes.low == 0x80) ? true : false;
            r->DE.bytes.low = add<uint8_t>(r->DE.bytes.low, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        }
    };
    instructions[oc] = i;

    // LD E,n
    oc = {0,0,0x001E};
    i = { 7, 7, 1, INST{ z->getRegisters()->DE.bytes.low = d[0]; } };
    instructions[oc] = i;

    // RRA
    oc = {0,0,0x001F};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.CF = rorc(r->AF.bytes.high, r->AF.bytes.low.CF);
            r->AF.bytes.low.HF = false;
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // JR NZ,d
    oc = {0,0,0x0020};
    i = { 7, 12, 1, INST{
            Z80Registers* r = z->getRegisters();
            if (r->AF.bytes.low.ZF == false)
            {
                r->PC += d[0];
            }
        }
    };
    instructions[oc] = i;

    // LD HL,nn
    oc = {0,0,0x0021};
    i = { 10, 10, 2, INST{ z->getRegisters()->HL.word = CREATE_WORD(d[0], d[1]); } };
    instructions[oc] = i;

    // LD (nn),HL
    oc = {0,0,0x0022};
    i = { 20, 20, 2, INST{
            uint16_t nn = CREATE_WORD(d[0], d[1]);
            (*m)[nn] = z->getRegisters()->HL.bytes.low;
            (*m)[nn+1] = z->getRegisters()->HL.bytes.high;            
        }
    };
    instructions[oc] = i;

    // INC HL
    oc = {0,0,0x0023};
    i = { 6, 6, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->HL.word = add<uint16_t>(r->HL.word, 1, r, INC16);
        }
    };
    instructions[oc] = i;

    // INC H
    oc = {0,0,0x0024};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->HL.bytes.high == 0x7F) ? true : false;
            r->HL.bytes.high = add<uint8_t>(r->HL.bytes.high, 1, r, INC8);
            r->AF.bytes.low.NF = false;
        }
    };
    instructions[oc] = i;

    // DEC H
    oc = {0,0,0x0025};
    i = { 4, 4, 0, INST{
            Z80Registers* r = z->getRegisters();
            r->AF.bytes.low.PF = (r->HL.bytes.high == 0x80) ? true : false;
            r->HL.bytes.high = add<uint8_t>(r->HL.bytes.high, -1, r, DEC8);
            r->AF.bytes.low.NF = true;
        }
    };
    instructions[oc] = i;

    // LD H,n
    oc = {0,0,0x0026};
    i = { 7, 7, 1, INST{ z->getRegisters()->HL.bytes.high = d[0]; } };
    instructions[oc] = i;

    // DAA
    oc = {0,0,0x0027};
    i = { 4, 4, 0, INST{ Z80Registers* r = z->getRegisters(); daa(r); } };
    instructions[oc] = i;

    return instructions;
}