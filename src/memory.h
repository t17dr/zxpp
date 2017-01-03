#pragma once

#include <stdint.h>

struct Spectrum48KMemory {
    uint8_t memory[0xFFFF];

    uint8_t* ROM = &memory[0x0000];
    uint8_t* screenMemory = &memory[0x4000];
    uint8_t* screenColorData = &memory[0x5800];
    uint8_t* printerBuffer = &memory[0x5B00];
    uint8_t* systemVariables = &memory[0x5C00];
    uint8_t* userMemory = &memory[0x5CCB];

    uint16_t ROM_size = 0x4000;
    uint16_t screen_size = 0x17FF;
    uint16_t screenColor_size = 0x02FF;
    uint16_t printerBuffer_size = 0x00FF;
    uint16_t systemVariables_size = 0x00BF;
    uint16_t userMemory_size = 0xA28C;
};