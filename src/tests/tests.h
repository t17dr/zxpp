#ifndef TESTS_H
#define TESTS_H

#include "../defines.h"

#include <iostream>

#include "../window.h"
#include "../z80.h"
#include "../instructions.h"

#define test(type, correct, input) _test<type>(correct, input, __FILE__, __LINE__)

template <typename T>
void _test(T correct, T input, char* file, int line);

// Simple instruction tests
// May need to use a proper unit testing framework in the future
void runTests(Z80& proc, Spectrum48KMemory& memory);

#endif