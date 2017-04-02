#pragma once

#include "3rdparty/imgui/impl/imgui_impl.h"
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

class Emulator;

#define KEYBOARD_TEXTURE_WIDTH 2048.0f
#define KEYBOARD_TEXTURE_HEIGHT 823.0f
#define TITLEBAR_HEIGHT 17.0f

const std::map<std::string, std::string> TEXTURE_FILES = {
    {"TEXTURE_KEYBOARD", "img/keyboard.png"}
};

// Positions and sizes of the keys for virtual keyboard on the texture
// First ImVec2 is position, second size, in pixels
const std::map<std::string, std::pair<ImVec2, ImVec2>> keyPositionsSizes = {
    {"ZX_1", {{79,98},{131,88}}},
    {"ZX_2", {{261,98},{131,88}}},
    {"ZX_3", {{441,98},{131,88}}},
    {"ZX_4", {{623,98},{131,88}}},
    {"ZX_5", {{799,98},{131,88}}},
    {"ZX_6", {{980,98},{131,88}}},
    {"ZX_7", {{1156,98},{131,88}}},
    {"ZX_8", {{1334,98},{131,88}}},
    {"ZX_9", {{1514,98},{131,88}}},
    {"ZX_0", {{1697,98},{131,88}}},
    {"ZX_Q", {{169,269},{131,88}}},
    {"ZX_W", {{351,269},{131,88}}},
    {"ZX_E", {{531,269},{131,88}}},
    {"ZX_R", {{710,269},{131,88}}},
    {"ZX_T", {{890,269},{131,88}}},
    {"ZX_Y", {{1067,269},{131,88}}},
    {"ZX_U", {{1245,269},{131,88}}},
    {"ZX_I", {{1424,269},{131,88}}},
    {"ZX_O", {{1606,269},{131,88}}},
    {"ZX_P", {{1793,269},{131,88}}},
    {"ZX_A", {{215,436},{131,88}}},
    {"ZX_S", {{397,436},{131,88}}},
    {"ZX_D", {{577,436},{131,88}}},
    {"ZX_F", {{756,436},{131,88}}},
    {"ZX_G", {{935,436},{131,88}}},
    {"ZX_H", {{1112,436},{131,88}}},
    {"ZX_J", {{1293,436},{131,88}}},
    {"ZX_K", {{1473,436},{131,88}}},
    {"ZX_L", {{1657,436},{131,88}}},
    {"ZX_ENTER", {{1841,436},{131,88}}},
    {"ZX_CAPS_SHIFT", {{77,604},{178,88}}},
    {"ZX_Z", {{307,604},{131,88}}},
    {"ZX_X", {{487,604},{131,88}}},
    {"ZX_C", {{667,604},{131,88}}},
    {"ZX_V", {{846,604},{131,88}}},
    {"ZX_B", {{1024,604},{131,88}}},
    {"ZX_N", {{1202,604},{131,88}}},
    {"ZX_M", {{1386,604},{131,88}}},
    {"ZX_SYMBOL_SHIFT", {{1567,604},{131,88}}},
    {"ZX_SPACE", {{1750,604},{227,88}}}
};

#pragma warning(push, 0)    // suppress warnings
#include "3rdparty/imgui/memory_edit.h"
#pragma warning(pop)

class Gui {
    public:
        Gui(Emulator* emu);
        void draw();
        void handleInput(SDL_Event &e);

        std::vector<std::string>* getVirtualKeyboardPressedKeys();
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

        std::vector<std::string> m_virtualKeyboardPressedKeys;
};