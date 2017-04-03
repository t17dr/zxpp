#pragma once

#include <SDL.h>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <string>

#include "3rdparty/imgui/imgui.h"

#include "devices.h"
#include "gui.h"

class Emulator;

class Keyboard : IDevice {
    public:
        Keyboard(Emulator* emu, Gui* gui);

        virtual void receiveData(uint8_t data, uint16_t port) override;
        virtual bool sendData(uint8_t& out, uint16_t port) override;

        // Map keycode to each keyboard key to m x n array
        // m determines the "row", 0 being the A8 (CAPS-V)
        // n determines the key in a row, 0 is outermost key
        static SDL_Keycode codes[8][5];

        // Unique strings identifying keys, same layout as "codes"
        static const std::string keyStrings[8][5];

        static std::string getKeyStringFromKeycode(SDL_Keycode k);
    private:
        Emulator* m_emu;
        Gui* m_gui;

};