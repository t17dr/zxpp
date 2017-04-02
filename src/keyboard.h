#pragma once

#include <SDL.h>
#include <stdint.h>
#include <vector>
#include <algorithm>

#include "3rdparty/imgui/imgui.h"

#include "devices.h"

class Emulator;

class Keyboard : IDevice {
    public:
        Keyboard(Emulator* emu);

        virtual void receiveData(uint8_t data, uint16_t port) override;
        virtual bool sendData(uint8_t& out, uint16_t port) override;
    private:
        Emulator* m_emu;

        // Map keycode to each keyboard key to m x n array
        // m determines the "row", 0 being the A8 (CAPS-V)
        // n determines the key in a row, 0 is outermost key
        static SDL_Keycode codes[8][5];
};