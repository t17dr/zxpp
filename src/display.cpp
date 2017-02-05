#include "display.h"

Display::Display(Spectrum48KMemory* memory, SDL_Renderer* renderer)
    : m_memory(memory),
      m_renderer(renderer)
{
    m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING,
                    DISPLAY_WIDTH, DISPLAY_HEIGHT);
    // char* m_pixels = new char[DISPLAY_WIDTH * DISPLAY_HEIGHT * 3];
}

Display::~Display()
{
    SDL_DestroyTexture(m_texture);
}

void Display::draw()
{
    // TODO: error handling
    
    void* pixels;
    int pitch;

    SDL_LockTexture(m_texture, NULL, &pixels, &pitch);

    for (uint8_t y = 0; y < DISPLAY_HEIGHT; y++)
    {
        for (uint8_t x = 0; x < DISPLAY_WIDTH/8; x++)
        {
            uint16_t memY = 0x4000 | ((y >> 6) << 11);
            memY |= (y & 0x7) << 8;
            memY |= ((y >> 3) & 0x7) << 5;

            uint16_t memPos = memY |= x;
            for (uint8_t bit = 0; bit < 8; bit++)
            {
                uint8_t value = ((*m_memory)[memPos] & (1 << bit)) > 0 ? 255 : 0;
                // SDL_SetRenderDrawColor(renderer, value, value, value, 255);

                ((uint8_t*)pixels)[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 ] = value;
                ((uint8_t*)pixels)[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 + 1 ] = value;
                ((uint8_t*)pixels)[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 + 2 ] = value;

                // SDL_RenderDrawPoint(renderer, x*8+bit, y);

                // SDL_Surface *surface = SDL_CreateRGBSurfaceFrom((void*)m_pixels,
                //     DISPLAY_WIDHT,
                //     DISPLAY_HEIGHT,
                //     24,                    // bpp
                //     DISPLAY_WIDTH * 3,     // pitch
                //     0xFF0000,              // red mask
                //     0x00FF00,              // green mask
                //     0x0000FF,              // blue mask
                //     0);                    // alpha mask (none)

                // t = SDL_CreateTextureFromSurface(m_renderer, surface);
                // SDL_Rect r = {0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT};*/
            }
        }
    }

    SDL_UnlockTexture(m_texture);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

}