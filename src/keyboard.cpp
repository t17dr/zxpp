
#include "emulator.h"
#include "keyboard.h"

SDL_Keycode Keyboard::codes[8][5] = {
            { SDLK_LSHIFT, SDLK_z, SDLK_x, SDLK_c, SDLK_v },
            { SDLK_a, SDLK_s, SDLK_d, SDLK_f, SDLK_g },
            { SDLK_q, SDLK_w, SDLK_e, SDLK_r, SDLK_t },
            { SDLK_1, SDLK_2, SDLK_3, SDLK_4, SDLK_5 },
            { SDLK_0, SDLK_9, SDLK_8, SDLK_7, SDLK_6 },
            { SDLK_p, SDLK_o, SDLK_i, SDLK_u, SDLK_y },
            { SDLK_RETURN, SDLK_l, SDLK_k, SDLK_j, SDLK_h },
            { SDLK_SPACE, SDLK_RSHIFT, SDLK_m, SDLK_n, SDLK_b }
        };

const std::string Keyboard::keyStrings[8][5] = {
    { "ZX_CAPS_SHIFT", "ZX_Z", "ZX_X", "ZX_C", "ZX_V" },
    { "ZX_A", "ZX_S", "ZX_D", "ZX_F", "ZX_G" },
    { "ZX_Q", "ZX_W", "ZX_E", "ZX_R", "ZX_T" },
    { "ZX_1", "ZX_2", "ZX_3", "ZX_4", "ZX_5" },
    { "ZX_0", "ZX_9", "ZX_8", "ZX_7", "ZX_6" },
    { "ZX_P", "ZX_O", "ZX_I", "ZX_U", "ZX_Y" },
    { "ZX_ENTER", "ZX_L", "ZX_K", "ZX_J", "ZX_H" },
    { "ZX_SPACE", "ZX_SYMBOL_SHIFT", "ZX_M", "ZX_N", "ZX_B" }
};

Keyboard::Keyboard(Emulator* emu, Gui* gui)
{
    m_emu = emu;
    m_gui = gui;
}

void Keyboard::receiveData(uint8_t data, uint16_t port)
{

}

bool Keyboard::sendData(uint8_t& out, uint16_t port)
{
    std::vector<SDL_Keycode>* keys = m_emu->getPressedKeys();
    std::vector<std::string>* virtualKeys = m_gui->getVirtualKeyboardPressedKeys();
    
    out = 0x1F; // TODO: change (to 0xFF?) when upper 3 bits of 0xFE port are implemented
    if ((port & 0x01) == 0)     // Port 0xFE
    {
        for (int m = 0; m < 8; m++)
        {
        // Row m
        if ((port & (1 << (m + 8))) == 0)
        {
            for (int n = 0; n < 5; n++)
            {
            // Check if key in column n is pressed
            if (std::find(keys->begin(), keys->end(), codes[m][n]) != keys->end() ||
                std::find(virtualKeys->begin(), virtualKeys->end(), keyStrings[m][n]) != virtualKeys->end())
            {
                out &= ~(1 << n);
            }
            }
        }
        }
        return true;
    }
    return false;
}