
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
    ImGui::SetNextWindowSize(ImVec2(400,70), NULL);
    if (!ImGui::Begin("Load ROM", &m_renderLoadROM, ImGuiWindowFlags_NoResize 
        | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse))
    {
        ImGui::End();
        return;
    }

    ImGui::PushItemWidth(-50);
    static char fileStr[260] = "48.rom";
    ImGui::InputText("", fileStr, 260);

    ImGui::SameLine();
    if (ImGui::SmallButton("..."))
    {
        const char* file = noc_file_dialog_open(NOC_FILE_DIALOG_OPEN, NULL, NULL, "48.rom");
        if (file != NULL)
        {
            if (strlen(file) < 260)
            {
                strcpy(fileStr, file);
            } else 
            {
                std::cerr << "File path too long (>260 characters)" << std::endl;
            }
        }
    }

    if (ImGui::Button("Load")) 
    {
        m_emu->loadROM(fileStr);
        m_emu->reset();
        m_renderLoadROM = false;
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel")) { m_renderLoadROM = false; }

    ImGui::End();
}
