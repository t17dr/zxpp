#include "window.h"

SDL_Window* createWindow(int width, int height, const char * title)
{
    SDL_Window *mainwindow;
    SDL_GLContext maincontext;

    std::cout << "Initializing video subsystem..." << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to initialize video subsystem: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    std::cout << "Creating window..." << std::endl;
    mainwindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!mainwindow)
    {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    maincontext = SDL_GL_CreateContext(mainwindow);
    if (maincontext == NULL)
    {
        std::cerr << "Failed to create openGL context: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    glewExperimental = true;
    glewInit();
    glLogLastError();
    glViewport(0, 0, width, height);
    glLogLastError();

    return mainwindow;
}