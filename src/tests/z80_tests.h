#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

#include "../z80.h"
#include "../memory.h"
#include "../debugger.h"
#include "../ula.h"
#include "../utils.h"

struct Z80TestCase {
    std::string description;
    Z80Registers inRegisters;
    bool inIFF1, inIFF2;
    int inInterruptMode;
    bool inHalted;
    int inTStates;
    std::vector<std::pair<uint16_t, uint8_t>> inMemory;

    Z80Registers outRegisters;
    bool outIFF1, outIFF2;
    int outInterruptMode;
    bool outHalted;
    int outTStates;
    std::vector<std::pair<uint16_t, uint8_t>> outMemory;

    // TODO: test contention?
};

template <typename T>
void assertEqual(T a, T b, Z80TestCase& t, std::string desc);

class Z80Tester {
    public:
        void parseTestFiles(std::string in, std::string expected);
        void runTests();
    protected:
        // Helper functions filling the input CPU state from input strings
        void parseRegisters(Z80Registers* r, std::vector<std::string>& str);
        void parseRegisters2(Z80TestCase* t, std::vector<std::string>& str, bool out = false);

        bool fillInput(Z80TestCase* testCase, std::ifstream& inStream);
        bool fillExpected(Z80TestCase* testCase, std::ifstream& inStream);

        // Compare test result with expected values
        void compareResults(Z80TestCase &test, Z80* z80);
    private:
        std::vector<Z80TestCase> m_testCases;
};