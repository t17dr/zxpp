
#include "emulator.h"

Emulator::Emulator(SDL_Window* window)
    : m_window(window),
      m_memory(),
      m_display(&m_memory),
      m_ula(),
      m_gui(this),
      m_keyboard(this, &m_gui),
      m_debugger(),
      m_proc(&m_memory, &m_ula, &m_debugger)
{
    init();
    m_proc.getIoPorts()->registerDevice((IDevice*)&m_keyboard);
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
    if (m_debugger.shouldBreak() && !m_debugger.shouldBreakNextFrame())
    { 
        if (timeSpan.count() >= REFRESH_RATE)
        {
            ImGui_ImplSdlGL3_NewFrame(m_window);
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            int w, h;
            SDL_GetWindowSize(m_window, &w, &h);
            m_display.draw(w, h);
            m_gui.draw();
            return true;
        }
        return false;
    }
    if ((timeSpan.count() >= REFRESH_RATE) || (m_debugger.shouldBreakNextFrame()))
    {
        ImGui_ImplSdlGL3_NewFrame(m_window);
        m_delta = timeSpan;
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_prevFrameTime = std::chrono::high_resolution_clock::now();

        int w, h;
        SDL_GetWindowSize(m_window, &w, &h);

        m_proc.nmi();
        m_proc.simulateFrame();
        m_display.draw(w, h);
        m_gui.draw();

        // m_pressedKeys.clear();
        m_debugger.endLoop();
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

Debugger* Emulator::getDebugger()
{
    return &m_debugger;
}

void Emulator::processEvent(SDL_Event e)
{
    m_gui.handleInput(e);

    switch (e.type)
    {
        case SDL_KEYDOWN:
            m_pressedKeys.push_back(e.key.keysym.sym);
            break;
        case SDL_KEYUP:
            m_pressedKeys.erase(
                std::remove(m_pressedKeys.begin(), m_pressedKeys.end(), e.key.keysym.sym),
                m_pressedKeys.end());
            break;
    }
}

std::vector<SDL_Keycode>* Emulator::getPressedKeys()
{
    return &m_pressedKeys;
}

Spectrum48KMemory* Emulator::getMemory()
{
    return &m_memory;
}
