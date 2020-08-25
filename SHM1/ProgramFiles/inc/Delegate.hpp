#pragma once

#include <stdint.h>

class Delegate {
public:
    virtual ~Delegate() = default;
    virtual void PayCrew(uint16_t) = 0;
};