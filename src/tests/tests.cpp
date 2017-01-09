#include "tests.h"

template <typename T>
void _test(T correct, T input, char* file, int line)
{
    if (correct == input) { std::cout << "."; }
    else 
    {
        std::cerr << std::endl << "Test did not pass: ";
        std::cerr << +input << " is not equal " << +correct;
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
    test(bool, 0, r->AF.bytes.low.PF );
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
    test(bool, 0, r->AF.bytes.low.PF );
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
    test(bool, 0, r->AF.bytes.low.PF );
    test(bool, 0, r->AF.bytes.low.NF );
    test(bool, 1, r->AF.bytes.low.CF );

    std::cout << std::endl;
}