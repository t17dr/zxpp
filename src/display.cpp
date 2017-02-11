#include "display.h"

Display::Display(Spectrum48KMemory* memory, SDL_Renderer* renderer)
    : m_memory(memory),
      m_renderer(renderer),
      m_inverted(false),
      m_frames(0)
{
    m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING,
                    DISPLAY_WIDTH, DISPLAY_HEIGHT);
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
                // Find the corresponding color attributes
                // http://www.animatez.co.uk/computers/zx-spectrum/screen-memory-layout/
                int xReal = x * 8 + bit;
                uint16_t memCol = 0x5800 + ( (y / 8) * (DISPLAY_WIDTH / 8) + (xReal / 8) );
                uint8_t attributes = (*m_memory)[memCol];
                
                // Find the color (each is stored as 1 bit per channel in GRB format)
                bool col = ((*m_memory)[memPos] & (1 << (7 - bit)));
                col = (m_inverted && (col >> 7)) ? !col : col;
                uint8_t r = col ? (attributes & 0x2) >> 1 : (attributes & 0x10) >> 4;
                uint8_t g = col ? (attributes & 0x4) >> 2 : (attributes & 0x20) >> 5;
                uint8_t b = col ? (attributes & 0x1) : (attributes & 0x8) >> 3;

                // Adjust by brightness flag
                r *= (attributes & 0x40) ? 255 : 128;
                g *= (attributes & 0x40) ? 255 : 128;
                b *= (attributes & 0x40) ? 255 : 128;

                ((uint8_t*)pixels)[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 ] = r;
                ((uint8_t*)pixels)[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 + 1 ] = g;
                ((uint8_t*)pixels)[ (DISPLAY_WIDTH * y + (x*8+bit)) * 3 + 2 ] = b;

            }
        }
    }

    SDL_UnlockTexture(m_texture);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

    m_frames++;
    if (m_frames > 15)
    {
        m_frames = 0;
        m_inverted = !m_inverted;
    }
}