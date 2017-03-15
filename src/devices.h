#pragma once

#include "defines.h"

#include <type_traits>

class IDevice {
    public:
    
    // Called when OUT instruction is executed
    virtual void receiveData(uint8_t data, uint16_t port) = 0;

    // Called when IN instruction is executed, should return true if this device
    // responds to the specified port address and place the byte on data bus
    // in out
    virtual bool sendData(uint8_t& out, uint16_t port) = 0;
};