#include "defines.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <glew.h>

#include <iostream>
#include <bitset>

#include "window.h"
#include "z80.h"
#include "instructions.h"
// #include "tests/tests.h"
#include "display.h"

#include <fstream>
#include <random>
#include <functional>
#include <string>
#include <chrono>
#include <memory>
#include <iomanip> // setprecision
#include <sstream> // stringstream

#include "utils.h"

#define REFRESH_RATE (1.0/50.0)

inline bool fileExists (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char* args[])
{
    SDL_Window* window = createWindow(256, 192, "ZX++");
    if (window == nullptr)
	{
		return -1;
	}

    Z80 proc;
    Spectrum48KMemory memory;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,255);
    auto dice = std::bind ( distribution, generator );
    for (int i = 0; i < memory.screen_size + memory.screenColor_size; i++)
    {
        int dice_roll = dice();
        *(memory.screenMemory + i) = (uint8_t) dice_roll;
    }

    // TODO: zkontrolovat "practically NOP" instrukce jestli nemaj nastavovat flagy
    // TODO: inkrementovat PC před(!) vykonanim instrukce, zkontrolovat ze skoky jdou spravne
    // TODO: disablovat maskable interrupty v prubehu DI a EI (+1 instrukce dal u EI)

    proc.init();

    std::string file = "48.rom";

    if (argc > 1)
    {
        file = std::string(args[1]);
    }
    std::ifstream inf;
    inf.open(file, std::ios::in|std::ios::binary);

    inf.seekg (0, std::ios::end);
    int length = (int)inf.tellg();
    inf.seekg (0, std::ios::beg);

    inf.read((char *)memory.ROM, length);

    inf.close();

    Display display(&memory);

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glLogLastError();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLogLastError();

	SDL_GL_SwapWindow(window);

    auto start = std::chrono::high_resolution_clock::now();

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


        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(now - start);

        if (timeSpan.count() >= REFRESH_RATE)
        {
            // std::string fps = std::to_string(1.0f/(float)timeSpan.count());
            std::stringstream stream;
            stream << std::fixed << std::setprecision(1) << 1.0f/(float)timeSpan.count();
            std::string fps = stream.str();
            fps = "ZXPP | FPS: " + fps;
            SDL_SetWindowTitle(window, fps.c_str());
            start = std::chrono::high_resolution_clock::now();
            
            proc.simulateFrame(&memory);
            display.draw();
        }

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}