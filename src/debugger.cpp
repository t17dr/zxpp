
#include "debugger.h"

uint16_t conditionToRegisterValue(BreakpointCondition c, Z80Registers* r)
{
    switch (c)
    {
        case BreakpointCondition::AF:  return r->AF.word;
        case BreakpointCondition::BC:  return r->BC.word;
        case BreakpointCondition::DE:  return r->DE.word;
        case BreakpointCondition::HL:  return r->HL.word;
        case BreakpointCondition::AFx: return r->AFx.word;
        case BreakpointCondition::BCx: return r->BCx.word;
        case BreakpointCondition::DEx: return r->DEx.word;
        case BreakpointCondition::HLx: return r->HLx.word;
        case BreakpointCondition::IX:  return r->IX.word;
        case BreakpointCondition::IY:  return r->IY.word;
        case BreakpointCondition::IR:  return r->IR.word;
        case BreakpointCondition::SP:  return r->SP;
        case BreakpointCondition::A:   return r->AF.bytes.high;
        case BreakpointCondition::F:   return r->AF.bytes.low.byte;
        case BreakpointCondition::D:   return r->DE.bytes.high;
        case BreakpointCondition::E:   return r->DE.bytes.low;
        case BreakpointCondition::H:   return r->HL.bytes.high;
        case BreakpointCondition::L:   return r->HL.bytes.low;
        case BreakpointCondition::I:   return r->IR.bytes.high;
        case BreakpointCondition::R:   return r->IR.bytes.low;
        default:  return 0;
    }
}

Breakpoint::Breakpoint(uint16_t address, BreakpointCondition cond,
            BreakpointConditionOperator op,
            uint16_t num)
    : m_address(address),
      m_condition(cond),
      m_operator(op),
      m_conditionNumber(num)
{
    m_is16bit = (cond > BreakpointCondition::NONE && cond <= BreakpointCondition::SP);
}

Breakpoint::Breakpoint()
{
    m_address = 0;
    m_condition = BreakpointCondition::NONE;
    m_operator = BreakpointConditionOperator::EQ;
    m_conditionNumber = 0;
    m_is16bit = false;
    m_enabled = false;
}

uint16_t* Breakpoint::getAddress()
{
    return &m_address;
}

BreakpointCondition* Breakpoint::getCondition()
{
    return &m_condition;
}

BreakpointConditionOperator* Breakpoint::getOperator()
{
    return &m_operator;
}

uint16_t* Breakpoint::getConditionNumber()
{
    return &m_conditionNumber;
}

bool Breakpoint::isCondition16bit()
{
    return m_is16bit;
}

bool* Breakpoint::getEnabled()
{
    return &m_enabled;
}

void Breakpoint::setConditionNumber(int num)
{
    m_conditionNumber = num;
}

void Breakpoint::setAddress(int addr)
{
    m_address = addr;
}

Debugger::Debugger()
    : m_lastIndex(0),
      m_breakExecution(false),
      m_breakNextFrame(false),
      selectedTrace(-1)
{}

int Debugger::addBreakpoint(Breakpoint breakpoint)
{
    m_breakpoints.emplace(++m_lastIndex, breakpoint);
    return m_lastIndex;
}

void Debugger::removeBreakpoint(int index)
{
    m_breakpoints.erase(index);
}

int Debugger::getBreakpointsCount()
{
    return (int)m_breakpoints.size();
}

std::map<int, Breakpoint>* Debugger::getBreakpoints()
{
    return &m_breakpoints;
}

std::vector<InstructionTrace>* Debugger::getTrace()
{
    return &m_trace;
}

void Debugger::addTrace(InstructionTrace trace)
{
    m_trace.push_back(trace);
}

void Debugger::breakExecution()
{
    m_breakExecution = true;
}

void Debugger::continueExecution()
{
    m_trace.clear();
    selectedTrace = -1;
    m_breakExecution = false;
}

bool Debugger::shouldBreak()
{
    return m_breakExecution;
}

void Debugger::breakNextFrame()
{
    m_breakNextFrame = true;
}

bool Debugger::shouldBreakNextFrame()
{
    return m_breakNextFrame;
}

void Debugger::endLoop()
{
    m_breakNextFrame = false;

    for (auto&& trace : m_trace)
    {
        parseMnemonicData(&trace);
    }
}

void Debugger::parseMnemonicData(InstructionTrace* t)
{
    size_t nn = t->mnemonic.find("nn");
    if (nn != std::string::npos)
    {
        std::stringstream stream;
        stream << std::hex << +(CREATE_WORD(t->bytes[0], t->bytes[1]));
        std::string strHex(stream.str());
        t->mnemonic.replace(nn, 2, strHex);
        return;
    }
    size_t n = t->mnemonic.find("n");
    if (n != std::string::npos)
    {
        std::stringstream stream;
        stream << std::hex << +(t->bytes[0]);
        std::string strHex(stream.str());
        t->mnemonic.replace(n, 1, strHex);
        return;
    }
    size_t d = t->mnemonic.find("d");
    if (d != std::string::npos)
    {
        std::stringstream stream;
        stream << std::hex << +(t->bytes[0]);
        std::string strHex(stream.str());
        t->mnemonic.replace(d, 1, strHex);
    }
}
