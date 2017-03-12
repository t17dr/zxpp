
#include "gui.h"

Gui::Gui()
    : m_renderMenu(true)
{

}

void Gui::draw()
{
    if (m_renderMenu)
    {
        renderMenu();
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
            if (ImGui::MenuItem("Load ROM")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Reset machine", "CTRL+R")) {}
            if (ImGui::MenuItem("Settings", "CTRL+K")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}