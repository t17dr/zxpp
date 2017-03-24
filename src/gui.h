#pragma once

#include "3rdparty/imgui/impl/imgui_impl.h"
#include "3rdparty/noc_file_dialog.h"
#include "3rdparty/iconfont/IconsFontAwesome.h"
#include "utils.h"
#include <SDL.h>
#include <cstring>
#include <iomanip>
#include <sstream> // stringstream
#include <bitset>

#include "emulator.h"

class Gui {
    public:
        Gui(Emulator* emu);
        void draw();
        void handleInput(SDL_Event &e);
    protected:
        void renderMenu();
        void renderLoadRomWindow();
        void renderDebugger();
    private:
        bool m_renderMenu;
        bool m_renderLoadROM;
        bool m_renderDebugger;
        bool m_renderMemoryEditor;

        Emulator* m_emu;
};