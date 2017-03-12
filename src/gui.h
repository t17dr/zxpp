#pragma once

#include "3rdparty/imgui/impl/imgui_impl.h"
#include <SDL.h>

class Gui {
    public:
        Gui();
        void draw();
        void handleInput(SDL_Event &e);
    protected:
        void renderMenu();
    private:
        bool m_renderMenu;
};