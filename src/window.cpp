#include "window.h"

SDL_Window* createWindow(int width, int height, const char * title)
{
    SDL_Window *mainwindow;

    std::cout << "Initializing video subsystem..." << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to initialize video subsystem: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    std::cout << "Creating window..." << std::endl;
    mainwindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!mainwindow)
    {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);

    return mainwindow;
}