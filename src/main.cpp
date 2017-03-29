#include "defines.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <glew.h>

#include "3rdparty/imgui/impl/imgui_impl.h"

#include <iostream>
#include <bitset>

#include "window.h"
#include "z80.h"
#include "instructions.h"
// #include "tests/tests.h"
#include "display.h"
#include "gui.h"
#include "emulator.h"
#include "tests/z80_tests.h"

#include <fstream>
#include <random>
#include <functional>
#include <string>
#include <chrono>
#include <memory>
#include <iomanip> // setprecision
#include <sstream> // stringstream

#include "utils.h"

inline bool fileExists (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char* args[])
{
    static bool showImguiDemo = false;

    SDL_Window* window = createWindow(800, 600, "ZX++");
    if (window == nullptr)
	{
		return -1;
	}

    Emulator emu(window);
    ImGui_ImplSdlGL3_Init(window);


    // Redirect cerr to log file
    std::ofstream out("output_log.txt");
    std::streambuf *coutbuf = std::cerr.rdbuf();
    std::cerr.rdbuf(out.rdbuf());
    Z80Tester tester;
    tester.parseTestFiles("tests.in", "tests.expected");
    tester.runTests();

    // TODO: zkontrolovat "practically NOP" instrukce jestli nemaj nastavovat flagy
    // TODO: disablovat maskable interrupty v prubehu DI a EI (+1 instrukce dal u EI)

    std::string file = "48.rom";

    if (argc > 1)
    {
        file = std::string(args[1]);
    }
    
    emu.loadROM(file);
    Gui gui(&emu);

    // Main loop
	bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            ImGui_ImplSdlGL3_ProcessEvent(&e);
            gui.handleInput(e);
            emu.processEvent(e);
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_WINDOWEVENT)
            {
                switch (e.window.event)
                {
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                    case SDL_WINDOWEVENT_RESIZED:
                        int w, h;
                        SDL_GetWindowSize(window, &w, &h);
                        glViewport(0, 0, w, h);
                        break;
                }
            }
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_F1)
                {
                    showImguiDemo = !showImguiDemo;
                }
            }
        }

        if (emu.loop())
        {

            std::stringstream stream;
            stream << std::fixed << std::setprecision(1) << 1.0f/(float)emu.getDeltaTime();
            std::string fps = stream.str();
            fps = "ZXPP | FPS: " + fps;
            SDL_SetWindowTitle(window, fps.c_str());
  
            if (showImguiDemo)
            {
                ImGui::ShowTestWindow();
            }
            gui.draw();
            ImGui::Render();

            SDL_GL_SwapWindow(window);
        }

    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}