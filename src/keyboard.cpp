
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

Keyboard::Keyboard(Emulator* emu)
{
    m_emu = emu;
}

void Keyboard::receiveData(uint8_t data, uint16_t port)
{

}

bool Keyboard::sendData(uint8_t& out, uint16_t port)
{
    ImGui::SetNextWindowSize(ImVec2(500,200), NULL);
    std::vector<SDL_Keycode>* keys = m_emu->getPressedKeys();
    if (keys->size() > 0)
    {
    if (!ImGui::Begin("Keyboard", (bool*)true, ImVec2(0, 30), 0.3f, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings))
    {
        ImGui::End();
        // return false;
    }
    ImGui::Text("Key 1: (%d)", (*keys)[0]);
    ImGui::End();
    } else {
        if (!ImGui::Begin("Keyboard", (bool*)true, ImVec2(0, 30), 0.3f, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings))
        {
            ImGui::End();
            // return false;
        }
        ImGui::Text("No key!");
        ImGui::End();
    }
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
            if (std::find(keys->begin(), keys->end(), codes[m][n]) != keys->end())
            {
                ImGui::SetNextWindowPos(ImVec2(10, 10));
                if (!ImGui::Begin("Keyboard", (bool*)true, ImVec2(0, 30), 0.3f, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings))
                {
                    ImGui::End();
                    // return false;
                }
                ImGui::Text("Pressed: (%d,%d)", m, n);
                ImGui::End();
                out &= ~(1 << n);
            }
            }
        }
        }
        return true;
    }
    return false;
}