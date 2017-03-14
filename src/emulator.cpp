
#include "emulator.h"

Emulator::Emulator(SDL_Window* window)
    : m_window(window),
      m_memory(),
      m_display(&m_memory),
      m_proc(&m_memory)
{
    init();
    m_prevFrameTime = std::chrono::high_resolution_clock::now();
}

void Emulator::init()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,255);
    auto dice = std::bind ( distribution, generator );
    for (int i = 0; i < m_memory.screen_size + m_memory.screenColor_size; i++)
    {
        int dice_roll = dice();
        *(m_memory.screenMemory + i) = (uint8_t) dice_roll;
    }

    m_proc.init();
}

void Emulator::loadROM(std::string filename)
{
    std::ifstream inf;
    inf.open(filename, std::ios::in|std::ios::binary);

    inf.seekg (0, std::ios::end);
    int length = (int)inf.tellg();
    inf.seekg (0, std::ios::beg);

    inf.read((char *)m_memory.ROM, length);

    inf.close();

    m_ROMfile = filename;
}

bool Emulator::loop()
{
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(now - m_prevFrameTime);
    if (timeSpan.count() >= REFRESH_RATE)
    {
        m_delta = timeSpan;
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui_ImplSdlGL3_NewFrame(m_window);

        m_prevFrameTime = std::chrono::high_resolution_clock::now();

        int w, h;
        SDL_GetWindowSize(m_window, &w, &h);

        m_proc.simulateFrame();
        m_display.draw(w, h);

        return true;
    }

    return false;

}

double Emulator::getDeltaTime()
{
    return m_delta.count();
}

void Emulator::reset()
{
    init();
    loadROM(m_ROMfile);
}

Display* Emulator::getDisplay()
{
    return &m_display;
}