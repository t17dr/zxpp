#pragma once

#include "3rdparty/imgui/impl/imgui_impl.h"
#include "3rdparty/noc_file_dialog.h"
#include "3rdparty/iconfont/IconsFontAwesome.h"

#include "gl_utils.h"
#include "utils.h"

#include <SDL.h>
#include <cstring>
#include <iomanip>
#include <sstream> // stringstream
#include <bitset>
#include <map>
#include <glew.h>

#include "emulator.h"

const std::map<std::string, std::string> TEXTURE_FILES = {
    {"TEXTURE_KEYBOARD", "img/keyboard.png"}
};

#pragma warning(push, 0)    // suppress warnings
#include "3rdparty/imgui/memory_edit.h"
#pragma warning(pop)

class Gui {
    public:
        Gui(Emulator* emu);
        void draw();
        void handleInput(SDL_Event &e);
    protected:
        void uploadTextures();

        void renderMenu();
        void renderLoadRomWindow();
        void renderDebugger();
        void renderMemoryEditor();
        void renderVirtualKeyboard();
    private:
        bool m_renderMenu;
        bool m_renderLoadROM;
        bool m_renderDebugger;
        bool m_renderMemoryEditor;
        bool m_renderVirtualKeyboard;

        Emulator* m_emu;
        std::map<std::string, GLuint> m_textureIDs;
};