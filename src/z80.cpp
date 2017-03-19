#include "z80.h"
#include "debugger.h"

int Z80::parseNextInstruction()
{
    uint16_t location = m_registers.PC;
    std::vector<uint8_t> bytes;

    // Do not use memory's operator[] to circumvent memory contention emulation
    while (prefixes.find(m_memory->memory[location]) != prefixes.end())
    {
        bytes.push_back((*m_memory)[location]);
        location++;
    }

    if (bytes.size() == 2 && ( (bytes[0] == 0xDD || bytes[0] == 0xFD) && bytes[1] == 0xCB ))
    {
        // if the prefixes are DDCB or FDCB, then the opcode is in forth byte after displacement byte
        location++;
    }
    bytes.push_back((*m_memory)[location]);
    
    if ( bytes.size() > 1 && bytes[1] == 0xED ) { bytes[0] = 0; }     // Ignore other prefixes before ED

    assert(bytes.size() <= 3);

    while (bytes.size() < 3) { bytes.insert(bytes.begin(), 0); }   // Pad with zeros

    int pref1 = 0;
    switch (bytes[0])
    {
        case 0xDD: pref1 = 1; break;
        case 0xFD: pref1 = 2; break;
        case 0xED: pref1 = 3; break;
        case 0xCB: pref1 = 4; break;
        default: pref1 = 0; break;
    }
    int pref2 = 0;
    switch (bytes[1])
    {
        case 0xDD: pref2 = 1; break;
        case 0xFD: pref2 = 2; break;
        case 0xED: pref2 = 3; break;
        case 0xCB: pref2 = 4; break;
        default: pref2 = 0; break;
    }

    // Compute the index in array, more info in instructions_preprocess.py
    return ((pref1 > 0) ? pref1 + 4 : 0) * 256 + pref2 * 256 + bytes[2];
}

void Z80::init()
{
    m_registers.PC = 0;
    m_IFF1 = 0;
    m_IFF2 = 0;
    m_registers.SP = 0xFFFF;
    m_registers.IX.word = 0xFFFF;
    m_registers.IY.word = 0xFFFF;
    m_registers.IR.word = 0x00FF;
    m_registers.AF.word = 0xFFFF;
    m_registers.BC.word = 0xFFFF;
    m_registers.DE.word = 0xFFFF;
    m_registers.HL.word = 0xFFFF;
    m_registers.AFx.word = 0xFFFF;
    m_registers.BCx.word = 0xFFFF;
    m_registers.DEx.word = 0xFFFF;
    m_registers.HLx.word = 0xFFFF;

    m_instructionSet = z80InstructionSet();
}

Z80::Z80(Spectrum48KMemory* m, ULA* ula, Debugger* debugger)
    : m_memory(m),
      m_ula(ula),
      m_debugger(debugger)
{
    init();
    m_cyclesSinceLastFrame = 0;
}

Z80Registers* Z80::getRegisters()
{
    return &m_registers;
}

Z80IOPorts* Z80::getIoPorts()
{
    return &m_ioPorts;
}

void Z80::setIFF1(bool b)
{
    m_IFF1 = b;
}

void Z80::setIFF2(bool b)
{
    m_IFF2 = b;
}

bool Z80::getIFF2()
{
    return m_IFF2;
}

void Z80::halt()
{
    m_isHalted = true;
}

int Z80::getInterruptMode()
{
    return m_interruptMode;
}

void Z80::setInterruptMode(int m)
{
    m_interruptMode = m;
}

int Z80::runInstruction(int instBytes)
{
    Instruction instruction = (*m_instructionSet)[instBytes];

    std::vector<uint8_t> data;
    int i = 0;
    if ( instBytes >= 2304 && instBytes <= 2815 )
    {
        // in DDCB and FDCB instructions, data byte is before opcode
        i = -1;
    }
    for (; i < instruction.numDataBytes; i++)
    {
        data.push_back((*m_memory)[m_registers.PC + i]);
    }

    m_registers.PC += instruction.numDataBytes;
    auto prevPC = m_registers.PC;

    instruction.execute(this, m_memory, data);

    int cyclesTaken = instruction.cycles;
    if (m_registers.PC != prevPC)       // Jump was taken
    {
        cyclesTaken = instruction.cyclesOnJump;
    }

    return cyclesTaken;
}

void Z80::nextInstruction()
{
    std::map<int, Breakpoint>* breakpoints = m_debugger->getBreakpoints();
    for (auto it = breakpoints->begin(); it != breakpoints->end(); ++it)
    {
        if ( *(it->second.getEnabled()) && *( it->second.getAddress()) == m_registers.PC )
        {
            // TODO: podminky
            m_debugger->breakExecution();
        }
    }
    int instruction = parseNextInstruction();
    int numBytes = ( instruction >= 5*256 ) ? 3 : ( instruction >= 256 ) ? 2 : 1;
    m_registers.PC += numBytes;
    int cycles = runInstruction(instruction);

    if (m_debugger->shouldBreak())
    {
        InstructionTrace trace;
        trace.address = m_registers.PC - numBytes;
        trace.registers = m_registers;
        trace.IFF1 = m_IFF1;
        trace.IFF2 = m_IFF2;
        trace.interruptMode = m_interruptMode;
        trace.frameCycleNumber = m_cyclesSinceLastFrame;
        trace.mnemonic = "NOP"; // TODO: mnemonic
        m_debugger->addTrace(trace);
    }

    m_cyclesSinceLastFrame += cycles;

}

void Z80::simulateFrame()
{
    while ( m_cyclesSinceLastFrame <= (1.0/50.0) / CLOCK_TIME )
    {
        nextInstruction();
    }
    m_cyclesSinceLastFrame = 0;
}


void Z80::printState()
{
    std::cout << std::hex;
    std::cout << "S = " << m_registers.AF.bytes.low.SF << " Z = " << m_registers.AF.bytes.low.ZF;
    std::cout << " P/O = " << m_registers.AF.bytes.low.PF << " N = " << m_registers.AF.bytes.low.NF;
    std::cout << " C = " << m_registers.AF.bytes.low.CF << " I = " << +m_registers.IR.bytes.high;
    std::cout << " R = " << +m_registers.IR.bytes.low << " IE = " << m_IFF1;
    std::cout << " IM = " << m_interruptMode << std::endl;

    std::cout << "A = " << +m_registers.AF.bytes.high << " BC = " << m_registers.BC.word;
    std::cout << " DE = " << m_registers.DE.word << " HL = " << m_registers.HL.word;
    std::cout << " SP = " << m_registers.SP << " PC = " << m_registers.PC << std::endl;

    std::cout << "Ax = " << +m_registers.AFx.bytes.high << " BCx = " << m_registers.BCx.word;
    std::cout << " DEx = " << m_registers.DEx.word << " HLx = " << m_registers.HLx.word;
    std::cout << " IX = " << m_registers.IX.word << " IY = " << m_registers.IY.word << std::endl;

    std::cout << "(HL) = " << +(m_memory->memory[m_registers.HL.word]) << std::endl;

}

void Z80IOPorts::registerDevice(IDevice* device)
{
    m_devices.push_back(device);
}

void Z80IOPorts::writeToPort(uint16_t port, uint8_t value)
{
    for (IDevice* d : m_devices)
    {
        d->receiveData(value, port);
    }
}

uint8_t Z80IOPorts::readPort(uint16_t port)
{
    uint8_t result = 0xFF;
    for (IDevice* d : m_devices)
    {
        uint8_t data;
        if (d->sendData(data, port))
        {
            result &= data;
        }
    }
    return result;
}

void Z80::nmi()
{
    if (!m_IFF1) { return; }
    m_IFF1 = false; m_IFF2 = false;
    int cycles;
    switch(m_interruptMode)
    {
        case 0:
            // Not used by the ULA, not completely implemented
            runInstruction(255);   // RST 38
            m_cyclesSinceLastFrame += 13;
            break;
        case 1:
            cycles = runInstruction(255);   // RST 38
            m_cyclesSinceLastFrame += cycles + 2;
            break;
        case 2:
            // Data bus value not implemented
            uint16_t pos = m_registers.IR.bytes.high * 256 + 255;
            uint8_t low = (*m_memory)[pos];
            uint8_t high = (*m_memory)[pos+1];
            uint16_t address = CREATE_WORD(low, high);
            m_registers.SP--;
            (*m_memory)[m_registers.SP] = m_registers.PC >> 8;
            m_registers.SP--;
            (*m_memory)[m_registers.SP] = m_registers.PC & 0xFF;
            m_registers.PC = address;
            m_cyclesSinceLastFrame += 19;
            break;
    }
}