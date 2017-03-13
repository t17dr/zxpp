#pragma once

#include "3rdparty/imgui/impl/imgui_impl.h"
#include <SDL.h>
#include "emulator.h"

class Gui {
    public:
        Gui(Emulator* emu);
        void draw();
        void handleInput(SDL_Event &e);
    protected:
        void renderMenu();
        void renderLoadRomWindow();
    private:
        bool m_renderMenu;
        bool m_renderLoadROM;

        Emulator* m_emu;
};