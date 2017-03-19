
#include "debugger.h"

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
    m_enabled = true;
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

bool Debugger::shouldBreak()
{
    return m_breakExecution;
}
