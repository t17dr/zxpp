#include "defines.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <iostream>
#include <bitset>

#include "window.h"
#include "z80.h"
#include "instructions.h"
#include "tests/tests.h"

int main(int argc, char* args[])
{
    SDL_Window* window = createWindow(256, 192, "ZX++");
    if (window == nullptr)
	{
		return -1;
	}

    Z80 proc;
    Spectrum48KMemory memory;

    // int16_t cislo = -32767;
    // proc.getRegisters()->BC.word = *reinterpret_cast<uint16_t*>(&cislo);

    // TODO: zkontrolovat "practically NOP" instrukce jestli nemaj nastavovat flagy
    // TODO: podminene jump instrukce musi vracet zda provedly skok kvuli casovani
    // TODO: inkrementovat PC před(!) vykonanim instrukce, zkontrolovat ze skoky jdou spravne
    // TODO: disablovat maskable interrupty v prubehu DI a EI (+1 instrukce dal u EI)
    
    runTests(proc, memory);

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