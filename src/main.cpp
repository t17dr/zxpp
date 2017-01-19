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

    // TODO: zkontrolovat "practically NOP" instrukce jestli nemaj nastavovat flagy
    // TODO: podminene jump instrukce musi vracet zda provedly skok kvuli casovani
    //                  -- !!update: nemusí, staci kontrolovat zda meni PC, tak se vyresi i LDIR
    // TODO: inkrementovat PC před(!) vykonanim instrukce, zkontrolovat ze skoky jdou spravne
    // TODO: disablovat maskable interrupty v prubehu DI a EI (+1 instrukce dal u EI)
    // TODO: nenalezeny instrukce = NOP
    // TODO: ignorovat DD,FD pred ED
    
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