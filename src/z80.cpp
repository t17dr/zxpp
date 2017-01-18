#include "z80.h"

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
}

Z80::Z80()
{
    init();
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

