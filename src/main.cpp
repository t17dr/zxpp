#include "defines.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <iostream>
#include <bitset>

#include "window.h"
#include "z80.h"
#include "instructions.h"

int main(int argc, char* args[])
{
    SDL_Window* window = createWindow(256, 192, "ZX++");
    if (window == nullptr)
	{
		return -1;
	}

    Z80 proc;
    Spectrum48KMemory memory;
    proc.getRegisters()->AF.bytes.low.CF = false;

    // int16_t cislo = -32767;
    // proc.getRegisters()->BC.word = *reinterpret_cast<uint16_t*>(&cislo);
    proc.getRegisters()->BC.word = 2;

    std::unordered_map<opcode, Instruction> instructions = z80InstructionSet();
    std::vector<uint8_t> data = { 0, 1 };
    opcode oc = { 0, 0, 0x0003 };
    instructions[oc].execute(&proc, &memory, data);

    std::cout << "BC (should 3): " << +proc.getRegisters()->BC.word << std::endl;
    proc.getRegisters()->BC.word = 582;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "BC (should 583): " << +proc.getRegisters()->BC.word << std::endl;

    Z80Registers* r = proc.getRegisters();

    int8_t cislo = -2;
    r->BC.bytes.high = *reinterpret_cast<uint8_t*>(&cislo);
    oc = {0, 0, 0x0004};
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should -1): " << + *reinterpret_cast<int8_t*>(&(proc.getRegisters()->BC.bytes.high)) << std::endl;
    std::cout << "S (should 1): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should 1): " << +r->BC.bytes.high << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    r->BC.bytes.high = 0x7F;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should 128): " << +r->BC.bytes.high << std::endl;
    
    oc = {0,0,0x0005};
    std::cout << "DEC B" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->BC.bytes.high = 1;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should 0): " << +r->BC.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 1): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should -1): " << + *reinterpret_cast<int8_t*>(&(r->BC.bytes.high)) << std::endl;
    std::cout << "S (should 1): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 1): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    r->BC.bytes.high = 16;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should 15): " << +r->BC.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 1): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should 14): " << +r->BC.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 1): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    r->BC.bytes.high = 14;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should 13): " << +r->BC.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 1): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    r->BC.bytes.high = 0x80;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "B (should 127): " << +r->BC.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 1): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 1): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    
    oc = {0,0,0x0007};
    std::cout << "RLCA" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 128;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 1): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 2): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    oc = {0,0,0x0008};
    std::cout << "EX AF, AF'" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->AF.word = 478;
    r->AFx.word = 974;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "AF (should 974): " << +r->AF.word << std::endl;
    std::cout << "AF' (should 478): " << +r->AFx.word << std::endl;

    oc = {0,0,0x0009};
    std::cout << "ADD HL, BC" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->HL.word = 11;
    r->BC.word = 52;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "HL (should 63): " << +r->HL.word << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    r->HL.word = 0xE00;
    r->BC.word = 0xE00;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "HL (should 7168): " << +r->HL.word << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    r->HL.word = 0xFFFE;
    r->BC.word = 0x12;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "HL (should 16): " << +r->HL.word << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;

    oc = {0,0,0x000B};
    std::cout << "DEC BC" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->BC.word = 52;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "BC (should 51): " << +r->BC.word << std::endl;

    oc = {0,0,0x000F};
    std::cout << "RRCA" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 1;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 128): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 64): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    oc = {0,0,0x0017};
    std::cout << "RLA" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 128;
    r->AF.bytes.low.CF = 0;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 0): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 1): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 2): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    oc = {0,0,0x001F};
    std::cout << "RRA" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->AF.bytes.high = 1;
    r->AF.bytes.low.CF = 0;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 0): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 128): " << +r->AF.bytes.high << std::endl;
    // std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    // std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    // std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    oc = {0,0,0x0027};
    std::cout << "DAA" << std::endl;
    std::cout << "-----------------" << std::endl;
    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.high = 0x85;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 133): " << +r->AF.bytes.high << std::endl;
    std::cout << "S (should 1): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.high = 0x0A;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 16): " << +r->AF.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 0;
    r->AF.bytes.high = 0x9B;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 1): " << +r->AF.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 1): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 0;
    r->AF.bytes.high = 0xA0;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 0): " << +r->AF.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 1): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 1;
    r->AF.bytes.high = 0x95;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 155): " << +r->AF.bytes.high << std::endl;
    std::cout << "S (should 1): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 0): " << +r->AF.bytes.low.CF << std::endl;

    r->AF.bytes.low.CF = 0;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 1;
    r->AF.bytes.high = 0xA0;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 6): " << +r->AF.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;

    r->AF.bytes.low.CF = 1;
    r->AF.bytes.low.NF = 0;
    r->AF.bytes.low.HF = 1;
    r->AF.bytes.high = 0x00;
    instructions[oc].execute(&proc, &memory, data);
    std::cout << "A (should 102): " << +r->AF.bytes.high << std::endl;
    std::cout << "S (should 0): " << +r->AF.bytes.low.SF << std::endl;
    std::cout << "Z (should 0): " << +r->AF.bytes.low.ZF << std::endl;
    std::cout << "H (should 0): " << +r->AF.bytes.low.HF << std::endl;
    std::cout << "P (should 0): " << +r->AF.bytes.low.PF << std::endl;
    std::cout << "N (should 0): " << +r->AF.bytes.low.NF << std::endl;
    std::cout << "C (should 1): " << +r->AF.bytes.low.CF << std::endl;

    // Main loop
	bool quit = false;
    SDL_Event e;
    while (!quit) 
    {
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_QUIT) 
            {
                quit = true;
            }
        }
    }

    return 0;
}