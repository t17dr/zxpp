#pragma once

#include <SDL.h>

#include "z80.h"
#include "memory.h"
#include "display.h"
#include "ula.h"
#include "keyboard.h"

#include "debugger.h"

#include <string>
#include <random>
#include <fstream>
#include <functional>

#include "3rdparty/imgui/impl/imgui_impl.h"

#define REFRESH_RATE (1.0/50.0)

class Emulator {
    public:
        Emulator(SDL_Window* window);

        void loadROM(std::string filename);

        // Compute and display 1 frame
        // Checks the frame time of 50Hz, returns if frame was actually rendered
        bool loop();

        // Get time in seconds since last frame
        double getDeltaTime();

        void reset();

        Display* getDisplay();
        Debugger* getDebugger();
        Spectrum48KMemory* getMemory();

        void processEvent(SDL_Event e);
        std::vector<SDL_Keycode>* getPressedKeys();
    protected:
        void init();
    private:
        Z80 m_proc;
        Spectrum48KMemory m_memory;
        Display m_display;
        ULA m_ula;
        Keyboard m_keyboard;
        Debugger m_debugger;
        std::string m_ROMfile;

        std::vector<SDL_Keycode> m_pressedKeys;

        SDL_Window* m_window;

        std::chrono::time_point<std::chrono::high_resolution_clock> m_prevFrameTime;
        std::chrono::duration<double> m_delta;
};