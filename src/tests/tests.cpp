#include "tests.h"

template <typename T>
void _test(T correct, T input, char* file, int line)
{
    if (correct == input) { std::cout << "."; }
    else 
    {
        std::cerr << std::endl << "Test did not pass: ";
        //std::cerr << +input << " is not equal " << +correct;
        
        std::cerr << " [" << file << "; line " << line << std::endl;
    }
}

void runTests(Z80& proc, Spectrum48KMemory& memory)
{
    proc.getRegisters()->AF.bytes.low.CF = false;

    proc.getRegisters()->BC.word = 2;

    std::unordered_map<opcode, Instruction> instructions = z80InstructionSet();
    std::vector<uint8_t> data = { 0, 1 };
    opcode oc = { 0, 0, 0x0003 };
    instructions[oc].execute(&proc, &memory, data);

    test(uint16_t, 3, proc.getRegisters()->BC.word);
    proc.getRegisters()->BC.word = 582;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 583, proc.getRegisters()->BC.word);

    Z80Registers* r = proc.getRegisters();

    int8_t cislo = -2;
    r->BC.bytes.high = *reinterpret_cast<uint8_t*>(&cislo);
    oc = {0, 0, 0x0004};
    instructions[oc].execute(&proc, &memory, data);
    test(int8_t, -1,  *reinterpret_cast<int8_t*>(&(proc.getRegisters()->BC.bytes.high)));
    test(bool, 1 , r->AF.bytes.low.SF);
    test(bool, 0 , r->AF.bytes.low.ZF);
    test(bool, 0 , r->AF.bytes.low.HF);
    test(bool, 0 , r->AF.bytes.low.PF);
    test(bool, 0 , r->AF.bytes.low.NF);
    test(bool, 0 , r->AF.bytes.low.CF);
    instructions[oc].execute(&proc, &memory, data);
    test(bool, 0, r->AF.bytes.low.SF);
    test(bool, 1, r->AF.bytes.low.ZF);
    test(bool, 1, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.PF);
    test(bool, 0, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 1, r->BC.bytes.high);
    test(bool, 0, r->AF.bytes.low.ZF);
    test(bool, 0, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.PF);
    test(bool, 0, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);
    r->BC.bytes.high = 0x7F;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 128, r->BC.bytes.high);
    
    oc = {0,0,0x0005};
    // std::cout << "DEC B" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->BC.bytes.high = 1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0, r->BC.bytes.high);
    test(bool, 0, r->AF.bytes.low.SF);
    test(bool, 1, r->AF.bytes.low.ZF);
    test(bool, 0, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.PF);
    test(bool, 1, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);
    instructions[oc].execute(&proc, &memory, data);
    test(int8_t, -1, *reinterpret_cast<int8_t*>(&(r->BC.bytes.high)) );
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->BC.bytes.high = 16;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 15, r->BC.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF);
    test(bool, 0, r->AF.bytes.low.ZF);
    test(bool, 1, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.PF);
    test(bool, 1, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 14, r->BC.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF);
    test(bool, 0, r->AF.bytes.low.ZF);
    test(bool, 0, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.PF);
    test(bool, 1, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);
    r->BC.bytes.high = 14;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 13, r->BC.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );
    r->BC.bytes.high = 0x80;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 127, r->BC.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );
    
    oc = {0,0,0x0007};
    // std::cout << "RLCA" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 128;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 1, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 2, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    oc = {0,0,0x0008};
    // std::cout << "EX AF, AF'" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->AF.word = 478;
    r->AFx.word = 974;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 974, r->AF.word);
    test(uint16_t, 478, r->AFx.word);

    oc = {0,0,0x0009};
    // std::cout << "ADD HL, BC" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->HL.word = 11;
    r->BC.word = 52;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 63, r->HL.word);
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->HL.word = 0xE00;
    r->BC.word = 0xE00;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 7168, r->HL.word);
    test(bool, 1, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);

    r->HL.word = 0xFFFE;
    r->BC.word = 0x12;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 16, r->HL.word);
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    oc = {0,0,0x000B};
    // std::cout << "DEC BC" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->BC.word = 52;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 51, r->BC.word);

    oc = {0,0,0x000F};
    // std::cout << "RRCA" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 128, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 64, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);

    oc = {0,0,0x0017};
    // std::cout << "RLA" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 128;
    r->AF.bytes.low.CF = 0;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 1, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 2, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    oc = {0,0,0x001F};
    // std::cout << "RRA" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 1;
    r->AF.bytes.low.CF = 0;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 128, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.HF);
    test(bool, 0, r->AF.bytes.low.NF);
    test(bool, 0, r->AF.bytes.low.CF);

    oc = {0,0,0x0027};
    // std::cout << "DAA" << std::endl;
    // std::cout << "-----------------" << std::endl;
    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.high = 0x85;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 133, r->AF.bytes.high );
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.high = 0x0A;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 16, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 0;
    r->AF.bytes.high = 0x9B;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 1, r->AF.bytes.high);
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 0;
    r->AF.bytes.high = 0xA0;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0, r->AF.bytes.high);
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 1, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 1;
    r->AF.bytes.high = 0x95;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 155, r->AF.bytes.high);
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 1;
    r->AF.bytes.high = 0xA0;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 6, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = 1;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 1;
    r->AF.bytes.high = 0x00;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 102, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    oc = {0,0,0x002F};
    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.high = 180;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 75, r->AF.bytes.high );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.NF );

    oc = {0,0,0x0080};
    r->AF.bytes.high = 3;
    r->BC.bytes.high = 2;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 5, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    oc = {0,0,0x0080};
    r->AF.bytes.high = 1;
    r->BC.bytes.high = 15;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 16, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    oc = {0,0,0x0080};
    r->AF.bytes.high = 128;
    r->BC.bytes.high = 129;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 1, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    oc = {0,0,0x0080};
    r->AF.bytes.high = 127;
    r->BC.bytes.high = 5;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 132, r->AF.bytes.high );
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    oc = {0,0,0x0080};
    r->AF.bytes.high = 255;
    r->BC.bytes.high = 1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0, r->AF.bytes.high ); 
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 1, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    // oc = {0,0,0x0086};
    // r->HL.word = 3571;
    // memory[3571] = 112;
    // instructions[oc].execute(&proc, &memory, data);
    // test(uint8_t, 112, r->AF.bytes.high ); 

    oc = {0,0,0x0086};
    r->AF.bytes.high = 3;
    r->HL.word = 3571;
    memory[3571] = 112;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 115, r->AF.bytes.high );

    oc = {0,0,0x0088};
    r->AF.bytes.high = 0x16;
    r->BC.bytes.high = 0x10;
    r->AF.bytes.low.CF = true;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x27, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.high = 0x16;
    r->BC.bytes.high = 0x10;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x26, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.high = 0x1F;
    r->BC.bytes.high = 0x10;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x2F, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.high = 0xFE;
    r->BC.bytes.high = 0x17;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x15, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    r->AF.bytes.high = 127;
    r->BC.bytes.high = 8;
    r->AF.bytes.low.CF = true;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 136, r->AF.bytes.high );
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    // SUB B
    oc = {0,0,0x0090};
    r->AF.bytes.high = 0x29;
    r->BC.bytes.high = 0x11;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x18, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.high = 1;
    r->BC.bytes.high = 15;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0xF2, r->AF.bytes.high );
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    r->AF.bytes.high = 15;
    r->BC.bytes.high = 15;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 1, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.high = -2;
    r->BC.bytes.high = 127;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 127, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    // SBC B
    oc = {0,0,0x0098};
    r->AF.bytes.low.CF = false;
    r->AF.bytes.high = 0x29;
    r->BC.bytes.high = 0x11;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x18, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = true;
    r->AF.bytes.high = 0x29;
    r->BC.bytes.high = 0x11;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x17, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = true;
    r->AF.bytes.high = 17;
    r->BC.bytes.high = 1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 15, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = false;
    r->AF.bytes.high = 17;
    r->BC.bytes.high = 1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 16, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    r->AF.bytes.low.CF = true;
    r->AF.bytes.high = 0;
    r->BC.bytes.high = 0;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, -1, r->AF.bytes.high );
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    // AND B
    oc = {0,0,0x00A0};
    r->AF.bytes.high = 0xC3;
    r->BC.bytes.high = 0x7B;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x43, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 1, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    // XOR B
    oc = {0,0,0x00A8};
    r->AF.bytes.high = 0x96;
    r->BC.bytes.high = 0x5D;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0xCB, r->AF.bytes.high );
    test(bool, 1, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    // OR B
    oc = {0,0,0x00B0};
    r->AF.bytes.high = 0x12;
    r->BC.bytes.high = 0x48;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x5A, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 1, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    // CP B
    oc = {0,0,0x00B8};
    r->AF.bytes.high = 0x63;
    r->BC.bytes.high = 0x60;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x63, r->AF.bytes.high );
    test(bool, 0, r->AF.bytes.low.SF );
    test(bool, 0, r->AF.bytes.low.ZF );
    test(bool, 0, r->AF.bytes.low.HF );
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 1, r->AF.bytes.low.NF );
    test(bool, 0, r->AF.bytes.low.CF );

    // RET NZ
    oc = {0,0,0x00C0};
    r->AF.bytes.low.ZF = false;
    r->SP = 0x2000;
    memory[0x2000] = 0xB5;
    memory[0x2001] = 0x18;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x2002, r->SP );
    test(uint16_t, 0x18B5, r->PC );

    // POP BC
    oc = {0,0,0x00C1};
    r->SP = 0x1000;
    memory[0x1000] = 0x55;
    memory[0x1001] = 0x33;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x3355, r->BC.word );
    test(uint16_t, 0x1002, r->SP );

    // CALL NZ,nn
    oc = {0,0,0x00C4};
    r->PC = 0x1A47;
    r->SP = 0x3002;
    memory[0x1A47] = 0xD4;
    memory[0x1448] = 0x35;
    memory[0x1A49] = 0x21;
    data.clear();
    data = { 0x35, 0x21 };
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x1A, memory[0x3001] );
    test(uint16_t, 0x47, memory[0x3000] );
    test(uint16_t, 0x3000, r->SP );
    test(uint16_t, 0x2135, r->PC );

    // PUSH BC
    oc = {0,0,0x00C5};
    r->BC.word = 0x2233;
    r->SP = 0x1007;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x22, memory[0x1006] );
    test(uint16_t, 0x33, memory[0x1005] );
    test(uint16_t, 0x1005, r->SP );

    // RST 00
    oc = {0,0,0x00C7};
    r->PC = 0x15B3;
    r->SP = 0x1007;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x15, memory[0x1006] );
    test(uint16_t, 0xB3, memory[0x1005] );
    test(uint16_t, 0x1005, r->SP );
    test(uint16_t, 0x0000, r->PC );

    // RET
    oc = {0,0,0x00C9};
    r->PC = 0x3535;
    r->SP = 0x2000;
    memory[0x2000] = 0xB5;
    memory[0x2001] = 0x18;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x2002, r->SP );
    test(uint16_t, 0x18B5, r->PC );

    // OUT (n),A
    oc = {0,0,0x00D3};
    r->AF.bytes.high = 0x23;
    data = { 0x01 };
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x23, (*(proc.getIoPorts()))[0x01] );

    // EXX
    oc = {0,0,0x00D9};
    r->BC.word = 0x2374;
    r->BCx.word = 0x5431;
    r->DE.word = 0x8FC4;
    r->DEx.word = 0xFFCE;
    r->HL.word = 0x1234;
    r->HLx.word = 0x0042;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x2374, r->BCx.word );
    test(uint16_t, 0x5431, r->BC.word );
    test(uint16_t, 0x8FC4, r->DEx.word );
    test(uint16_t, 0xFFCE, r->DE.word );
    test(uint16_t, 0x1234, r->HLx.word );
    test(uint16_t, 0x0042, r->HL.word );

    // EX (SP),HL
    oc = {0,0,0x00E3};
    r->HL.word = 0x7012;
    r->SP = 0x8856;
    memory[0x8856] = 0x11;
    memory[0x8857] = 0x22;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x2211, r->HL.word );
    test(uint8_t, 0x12, memory[0x8856] );
    test(uint8_t, 0x70, memory[0x8857] );
    test(uint16_t, 0x8856, r->SP );

    // INC (IX+d)
    oc = {0,0xDD,0x0034};
    r->IX.word = 0x1245;
    data = { 0x71 };
    memory[0x12B6] = 0xF8;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0xF9, memory[0x12B6] );

    // SBC HL,BC
    oc = {0,0xED,0x0042};
    r->HL.word = 0x9999;
    r->BC.word = 0x1111;
    r->AF.bytes.low.CF = true;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x8887, r->HL.word );
    test(bool, true, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.CF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.PF );

    r->HL.word = 0x8000;
    r->BC.word = 0x0100;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x7F00, r->HL.word );
    test(bool, false, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.CF );
    test(bool, true, r->AF.bytes.low.HF );
    test(bool, true, r->AF.bytes.low.PF );

    r->HL.word = 0x4000;
    r->BC.word = 0x8100;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0xBF00, r->HL.word );
    test(bool, true, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.NF );
    test(bool, true, r->AF.bytes.low.CF );
    test(bool, true, r->AF.bytes.low.HF );
    test(bool, true, r->AF.bytes.low.PF );

    // NEG
    oc = {0,0xED,0x0044};
    r->AF.bytes.high = 0x98;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x68, r->AF.bytes.high );
    test(bool, false, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.NF );
    test(bool, true, r->AF.bytes.low.CF );
    test(bool, true, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.PF );

    // RRD
    oc = {0,0xED,0x0067};
    r->AF.bytes.high = 0x84;
    r->HL.word = 0x5000;
    memory[0x5000] = 0x20;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x80, r->AF.bytes.high );
    test(uint8_t, 0x42, memory[0x5000] );
    test(bool, true, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.CF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.PF );

    // RLD
    oc = {0,0xED,0x006F};
    r->AF.bytes.high = 0x7A;
    r->HL.word = 0x5000;
    memory[0x5000] = 0x31;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x73, r->AF.bytes.high );
    test(uint8_t, 0x1A, memory[0x5000] );
    test(bool, false, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.CF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.PF );

    // LDI
    oc = {0,0xED,0x00A0};
    r->BC.word = 0x7;
    r->HL.word = 0x1111;
    r->DE.word = 0x2222;
    memory[0x1111] = 0x88;
    memory[0x2222] = 0x66;
    r->AF.bytes.low.CF = false;
    instructions[oc].execute(&proc, &memory, data);
    test(uint16_t, 0x1112, r->HL.word );
    test(uint16_t, 0x2223, r->DE.word );
    test(uint16_t, 0x6, r->BC.word );
    test(uint8_t, 0x88, memory[0x1111] );
    test(uint8_t, 0x88, memory[0x2222] );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, true, r->AF.bytes.low.PF );

    // SLA B
    oc = {0,0xCB,0x0020};
    r->BC.bytes.high = 0xB1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x62, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.PF );
    test(bool, false, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.CF );

    // SLA (HL)
    oc = {0,0xCB,0x0026};
    memory[0x7823] = 0xB1;
    r->HL.word = 0x7823;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x62, memory[0x7823] );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.PF );
    test(bool, false, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.CF );

    // SRA B
    oc = {0,0xCB,0x0028};
    r->BC.bytes.high = 0xB8;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0xDC, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.PF );
    test(bool, true, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, false, r->AF.bytes.low.CF );

    // SLL B
    oc = {0,0xCB,0x0030};
    r->BC.bytes.high = 0xB1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x63, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, true, r->AF.bytes.low.PF );
    test(bool, false, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.CF );

    // SRL B
    oc = {0,0xCB,0x0038};
    r->BC.bytes.high = 0x8F;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x47, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, false, r->AF.bytes.low.HF );
    test(bool, true, r->AF.bytes.low.PF );
    test(bool, false, r->AF.bytes.low.SF );
    test(bool, false, r->AF.bytes.low.ZF );
    test(bool, true, r->AF.bytes.low.CF );

    // BIT 0,B
    oc = {0,0xCB,0x0040};
    r->BC.bytes.high = 0x3;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x3, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, true, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.ZF );

    // BIT 0,B
    oc = {0,0xCB,0x0040};
    r->BC.bytes.high = 0x2;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x2, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, true, r->AF.bytes.low.HF );
    test(bool, true, r->AF.bytes.low.ZF );

    // BIT 1,B
    oc = {0,0xCB,0x0048};
    r->BC.bytes.high = 0x2;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x2, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, true, r->AF.bytes.low.HF );
    test(bool, false, r->AF.bytes.low.ZF );

    // BIT 1,B
    oc = {0,0xCB,0x0048};
    r->BC.bytes.high = 0x1;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x1, r->BC.bytes.high );
    test(bool, false, r->AF.bytes.low.NF );
    test(bool, true, r->AF.bytes.low.HF );
    test(bool, true, r->AF.bytes.low.ZF );

    // RES 0,B
    oc = {0,0xCB,0x0080};
    r->BC.bytes.high = 0x3;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x2, r->BC.bytes.high );

    // RES 0,(HL)
    oc = {0,0xCB,0x0086};
    memory[0x5673] = 0x3;
    r->HL.word = 0x5673;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x2, memory[0x5673] );

    // RES 1,B
    oc = {0,0xCB,0x0088};
    r->BC.bytes.high = 0x3;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x1, r->BC.bytes.high );

    // SET 0,B
    oc = {0,0xCB,0x00C0};
    r->BC.bytes.high = 0x4;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x5, r->BC.bytes.high );

    // SET 0,(HL)
    oc = {0,0xCB,0x00C6};
    memory[0x6045] = 0x4;
    r->HL.word = 0x6045;
    instructions[oc].execute(&proc, &memory, data);
    test(uint8_t, 0x5, memory[0x6045] );

    // Instruction parsing
    std::vector<uint8_t> bytes = { 0xDD, 0x4B };
    opcode a = parseNextInstruction(bytes.data());
    opcode b = {0, 0xDD, 0x4B};
    test(opcode, b, a);

    bytes = { 0xED, 0x12 };
    a = parseNextInstruction(bytes.data());
    b = {0, 0xED, 0x12};
    test(opcode, b, a);

    bytes = { 0xFD, 0xED, 0x4B };
    a = parseNextInstruction(bytes.data());
    b = {0, 0xED, 0x4B};
    test(opcode, b, a);

    bytes = { 0xDD, 0xCB, 0xFF };
    a = parseNextInstruction(bytes.data());
    b = {0xDD, 0xCB, 0xFF};
    test(opcode, b, a);

    std::cout << std::endl;
}