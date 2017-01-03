#include <SDL.h>
#include <SDL_syswm.h>
#include <iostream>

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
    proc.getRegisters()->BC.word = 0;
    std::unordered_map<opcode, Instruction> instructions = z80InstructionSet();
    std::vector<uint8_t> data = { 5, 0 };
    opcode oc = { 0, 0, 0x0001 };
    instructions[oc].execute(&proc, &memory, data);
    std::cout << proc.getRegisters()->BC.word << std::endl;

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