#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <SDL.h>
#include "memory.h"

#define DISPLAY_WIDTH 256
#define DISPLAY_HEIGHT 192

class Display {
    public:
        Display(Spectrum48KMemory* memory, SDL_Renderer* renderer);
        ~Display();
        void draw();
    private:
        Spectrum48KMemory* m_memory;
        // SDL_Point* m_points;
        // char* m_pixels;
        SDL_Texture* m_texture;
        SDL_Renderer* m_renderer;
};

#endif