#pragma once

#include "algorithm"
#include "cmath"
#include "stdint.h"

class Coordinates {
    const uint16_t positionX_;
    const uint16_t positionY_;

public:
    Coordinates(uint16_t, uint16_t);
    uint16_t GetPositionX() const;
    uint16_t GetPositionY() const;
    static uint16_t Distance(const Coordinates&, const Coordinates&);
    bool operator==(const Coordinates&) const;
};