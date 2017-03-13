#pragma once

#include <SDL.h>

#include "z80.h"
#include "memory.h"
#include "display.h"

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
    protected:
        void init();
    private:
        Z80 m_proc;
        Spectrum48KMemory m_memory;
        Display m_display;
        std::string m_ROMfile;

        SDL_Window* m_window;

        std::chrono::time_point<std::chrono::high_resolution_clock> m_prevFrameTime;
        std::chrono::duration<double> m_delta;
};