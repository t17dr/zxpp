
#include "gui.h"

Gui::Gui(Emulator* emu)
    : m_renderMenu(true),
      m_emu(emu)
{

}

void Gui::draw()
{
    if (m_renderMenu)
    {
        renderMenu();
    }
    if (m_renderLoadROM)
    {
        renderLoadRomWindow();
    }
}

void Gui::handleInput(SDL_Event &e)
{

}

void Gui::renderMenu()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Load ROM")) { m_renderLoadROM = true; }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Reset machine", "CTRL+R")) { m_emu->reset(); }
            if (ImGui::MenuItem("Settings", "CTRL+K")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void Gui::renderLoadRomWindow()
{
    ImGui::SetNextWindowSize(ImVec2(400,200), ImGuiSetCond_FirstUseEver);
    if (!ImGui::Begin("Load ROM", (bool*)true, ImGuiWindowFlags_NoTitleBar
            | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar
            | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::End();
        return;
    }

    static char fileStr[260] = "48.rom";
    ImGui::InputText("ROM file", fileStr, 260);

    if (ImGui::Button("Load")) 
    {
        m_emu->loadROM(fileStr);
        m_emu->reset();
        m_renderLoadROM = false;
    }
    if (ImGui::Button("Cancel")) { m_renderLoadROM = false; }

    ImGui::End();
}
