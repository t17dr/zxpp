
#include "z80_tests.h"

void Z80Tester::parseTestFiles(std::string in, std::string expected)
{
    std::ifstream inStream, expectedStream;
    inStream.open(in, std::ios::in);
    expectedStream.open(expected, std::ios::in);

    if (!inStream.is_open())
    {
        std::cerr << "Test input file failed to open" << std::endl;
        return;
    }
    if (!expectedStream.is_open())
    {
        std::cerr << "Test output file failed to open" << std::endl;
        return;
    }

    for (;;)
    {
        Z80TestCase testCase;
        bool eof = fillInput(&testCase, inStream);
        bool eof2 = fillExpected(&testCase, expectedStream);
        m_testCases.push_back(testCase);
        if (eof || eof2) { break; }
    }

    inStream.close();
    expectedStream.close();
}

bool Z80Tester::fillInput(Z80TestCase* testCase, std::ifstream& inStream)
{
    std::string line;
    getline(inStream, line);
    testCase->description = line;
    getline(inStream, line);
    std::vector<std::string> registers = splitByWhitespace(line);
    parseRegisters(&(testCase->inRegisters), registers);
    getline(inStream, line);
    std::vector<std::string> registers2 = splitByWhitespace(line);
    parseRegisters2(testCase, registers2, false);
    getline(inStream, line);
    while (line != "-1")
    {
        // Parse input memory state
        std::vector<std::string> memoryLine = splitByWhitespace(line);
        uint16_t address = (uint16_t) std::stoi(memoryLine[0], 0, 16);
        for (auto it = ++(memoryLine.begin()); it != memoryLine.end()-1; ++it)
        {
            uint8_t byte = (uint8_t) std::stoi(*it, 0, 16);
            testCase->inMemory.push_back(std::pair<uint16_t,uint8_t>
                ( address, byte ));
            address++;
        }

        getline(inStream, line);
    }
    bool eof = false;
    while (true) {
        char ch = inStream.peek();
        if (ch == EOF) { eof = true; return eof; }
        if (ch != '\n') { break; }
        inStream.get();
    }
    
    return eof;
}

bool Z80Tester::fillExpected(Z80TestCase* testCase, std::ifstream& inStream)
{
    std::string line;
    getline(inStream, line);
    testCase->description = line;
    std::vector<std::string> lineVec;
    do {
        // Skip the machine cycle type and contention for now
        getline(inStream, line);
        lineVec = splitByWhitespace(line);
    } while (lineVec.size() < 5);
    std::vector<std::string> registers = splitByWhitespace(line);
    parseRegisters(&(testCase->outRegisters), registers);
    getline(inStream, line);
    std::vector<std::string> registers2 = splitByWhitespace(line);
    parseRegisters2(testCase, registers2, true);
    getline(inStream, line);
    while (line != "" && line != "\n" && line != "\r\n")
    {
        // Parse input memory state
        std::vector<std::string> memoryLine = splitByWhitespace(line);
        uint16_t address = (uint16_t) std::stoi(memoryLine[0], 0, 16);
        for (auto it = ++(memoryLine.begin()); it != memoryLine.end()-1; ++it)
        {
            uint8_t byte = (uint8_t) std::stoi(*it, 0, 16);
            testCase->outMemory.push_back(std::pair<uint16_t,uint8_t>
                ( address, byte ));
            address++;
        }

        getline(inStream, line);
    }
    
    return false;
}

void Z80Tester::parseRegisters(Z80Registers* r, std::vector<std::string>& str)
{
    try {
        r->AF.word = (uint16_t) std::stoi(str[0], 0, 16);
        r->BC.word = (uint16_t) std::stoi(str[1], 0, 16);
        r->DE.word = (uint16_t) std::stoi(str[2], 0, 16);
        r->HL.word = (uint16_t) std::stoi(str[3], 0, 16);
        r->AFx.word = (uint16_t) std::stoi(str[4], 0, 16);
        r->BCx.word = (uint16_t) std::stoi(str[5], 0, 16);
        r->DEx.word = (uint16_t) std::stoi(str[6], 0, 16);
        r->HLx.word = (uint16_t) std::stoi(str[7], 0, 16);
        r->IX.word = (uint16_t) std::stoi(str[8], 0, 16);
        r->IY.word = (uint16_t) std::stoi(str[9], 0, 16);
        r->SP = (uint16_t) std::stoi(str[10], 0, 16);
        r->PC = (uint16_t) std::stoi(str[11], 0, 16);    // TODO: memptr
    } catch(std::invalid_argument e) {
        std::cerr << "Error parsing test file when trying to convert value to integer" << std::endl;
    }
}

void Z80Tester::parseRegisters2(Z80TestCase* t, std::vector<std::string>& str, bool out)
{
    Z80Registers* r = out ? &(t->outRegisters) : &(t->inRegisters);
    try {
        r->IR.bytes.high = (uint8_t) std::stoi(str[0], 0, 16);
        r->IR.bytes.low = (uint8_t) std::stoi(str[1], 0, 16);
        if (!out)
        {
            t->inIFF1 = (bool) std::stoi(str[2]);
            t->inIFF2 = (bool) std::stoi(str[3]);
            t->inInterruptMode = std::stoi(str[4]);
            t->inHalted = (bool) std::stoi(str[5]);
            t->inTStates = std::stoi(str[6]);
        } else {
            t->outIFF1 = (bool) std::stoi(str[2]);
            t->outIFF2 = (bool) std::stoi(str[3]);
            t->outInterruptMode = std::stoi(str[4]);
            t->outHalted = (bool) std::stoi(str[5]);
            t->outTStates = std::stoi(str[6]);
        }
    } catch(std::invalid_argument e) {
        std::cerr << "Error parsing test file when trying to convert value to integer" << std::endl;
    }
}

void Z80Tester::runTests()
{
    Debugger d;
    ULA ula;
    Spectrum48KMemory memory;
    Z80 z80(&memory, &ula, &d);

    for (auto test : m_testCases)
    {
        z80.init();
        z80.m_registers = test.inRegisters;
        z80.m_IFF1 = test.inIFF1;
        z80.m_IFF2 = test.inIFF2;
        z80.m_interruptMode = test.inInterruptMode;
        z80.m_isHalted = test.inHalted;

        for (auto record : test.inMemory)
        {
            memory.memory[record.first] = record.second;
        }

        while (z80.m_cyclesSinceLastFrame < test.inTStates)
        {
            z80.nextInstruction();
        }

        compareResults(test, &z80);
    }
}

template <typename T>
void assertEqual(T a, T b, Z80TestCase& t, std::string desc)
{
    if (a != b)
    {
        std::cerr << "Error running test case '";
        std::cerr << t.description << "', ";
        std::cerr << +a << " should be " << +b;
        std::cerr << " (" << desc.c_str() << ")" << std::endl;
    }
}

void Z80Tester::compareResults(Z80TestCase &test, Z80* z80)
{
    assertEqual(z80->m_registers.PC, test.outRegisters.PC, test, "PC");
    assertEqual(z80->m_registers.SP, test.outRegisters.SP, test, "SP");
    assertEqual(z80->m_registers.IX.word, test.outRegisters.IX.word, test, "IX");
    assertEqual(z80->m_registers.IY.word, test.outRegisters.IY.word, test, "IY");

    // TODO: uncomment when IR handling is implemented
    // assertEqual(z80->m_registers.IR.word, test.outRegisters.IR.word, test, "IR");
    assertEqual(z80->m_registers.AF.bytes.high, test.outRegisters.AF.bytes.high, test, "A");

    assertEqual(z80->m_registers.AF.bytes.low.CF, test.outRegisters.AF.bytes.low.CF, test, "CF");
    assertEqual(z80->m_registers.AF.bytes.low.NF, test.outRegisters.AF.bytes.low.NF, test, "NF");
    assertEqual(z80->m_registers.AF.bytes.low.PF, test.outRegisters.AF.bytes.low.PF, test, "PF");
    // TODO: resit nedokumentovany XF a YF?
    // assertEqual(z80->m_registers.AF.bytes.low.XF, test.outRegisters.AF.bytes.low.XF, test, "XF");
    assertEqual(z80->m_registers.AF.bytes.low.HF, test.outRegisters.AF.bytes.low.HF, test, "HF");
    // assertEqual(z80->m_registers.AF.bytes.low.YF, test.outRegisters.AF.bytes.low.YF, test, "YF");
    assertEqual(z80->m_registers.AF.bytes.low.ZF, test.outRegisters.AF.bytes.low.ZF, test, "ZF");
    assertEqual(z80->m_registers.AF.bytes.low.SF, test.outRegisters.AF.bytes.low.SF, test, "SF");

    assertEqual(z80->m_registers.BC.word, test.outRegisters.BC.word, test, "BC");
    assertEqual(z80->m_registers.DE.word, test.outRegisters.DE.word, test, "DE");
    assertEqual(z80->m_registers.HL.word, test.outRegisters.HL.word, test, "HL");
    assertEqual(z80->m_registers.AFx.word, test.outRegisters.AFx.word, test, "AFx");
    assertEqual(z80->m_registers.BCx.word, test.outRegisters.BCx.word, test, "BCx");
    assertEqual(z80->m_registers.DEx.word, test.outRegisters.DEx.word, test, "DEx");
    assertEqual(z80->m_registers.HLx.word, test.outRegisters.HLx.word, test, "HLx");

    assertEqual(z80->m_IFF1, test.outIFF1, test, "IFF1");
    assertEqual(z80->m_IFF2, test.outIFF2, test, "IFF2");
    assertEqual(z80->m_isHalted, test.outHalted, test, "halted");
    assertEqual(z80->m_interruptMode, test.outInterruptMode, test, "IM");
    assertEqual(z80->m_cyclesSinceLastFrame, test.outTStates, test, "T-states");

    for (auto record : test.outMemory)
    {
        std::stringstream stream;
        stream << std::hex << record.first;
        std::string s = "Memory location " + stream.str();
        assertEqual(z80->m_memory->memory[record.first], record.second, test, s);
    }
}
