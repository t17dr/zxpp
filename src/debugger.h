#pragma once

#include <stdint.h>
#include <map>
#include <utility>
#include <iostream>
#include <iomanip>
#include <sstream> // stringstream

#include "z80.h"

enum class BreakpointCondition { 
    NONE = 0, AF = 1, BC, DE, HL, AFx, BCx, DEx, HLx, IX, IY, IR, SP,
    A, F, D, E, H, L, I, R
 };

enum class BreakpointConditionOperator {
    GT, LT, EQ, GE, LE, NE
};

// Get value of the register specified by c
uint16_t conditionToRegisterValue(BreakpointCondition c, Z80Registers* r);

class Breakpoint {
    public:
        Breakpoint(uint16_t address, BreakpointCondition cond = BreakpointCondition::NONE,
            BreakpointConditionOperator op = BreakpointConditionOperator::LT,
            uint16_t num = 0);
        Breakpoint();
        uint16_t* getAddress();
        BreakpointCondition* getCondition();
        BreakpointConditionOperator* getOperator();
        uint16_t* getConditionNumber();
        bool* getEnabled();
        bool isCondition16bit();

        void setConditionNumber(int num);
        void setAddress(int addr);
    private:
        uint16_t m_address;
        BreakpointCondition m_condition;
        BreakpointConditionOperator m_operator;
        uint16_t m_conditionNumber;
        bool m_is16bit;
        bool m_enabled;
};

struct InstructionTrace {
    uint16_t address;
    Z80Registers registers;
    std::string mnemonic;
    bool IFF1, IFF2;
    int interruptMode;
    int frameCycleNumber;
    std::vector<uint8_t> bytes;
    std::vector<uint8_t> opcodeBytes;
};

class Debugger {
    public:
        Debugger();

        int addBreakpoint(Breakpoint breakpoint);
        void removeBreakpoint(int index);
        int getBreakpointsCount();
        std::map<int, Breakpoint>* getBreakpoints();

        std::vector<InstructionTrace>* getTrace();
        void addTrace(InstructionTrace trace);
        int selectedTrace;

        void breakExecution();
        void continueExecution();
        bool shouldBreak();
        void breakNextFrame();
        bool shouldBreakNextFrame();

        void endLoop();

        // Replace mnemonic data with actual current data
        void parseMnemonicData(InstructionTrace* t);
    private:
        std::map<int, Breakpoint> m_breakpoints;
        std::vector<InstructionTrace> m_trace;
        int m_lastIndex;
        bool m_breakExecution;
        bool m_breakNextFrame;
};