#pragma once

#include "algorithm"
#include "cmath"
#include "stdint.h"

class Coordinates {
    const uint8_t positionX_;
    const uint8_t positionY_;

public:
    Coordinates(uint8_t, uint8_t);
    uint8_t GetPositionX() const { return positionX_; }
    uint8_t GetPositionY() const { return positionY_; }
    static uint16_t Distance(const Coordinates&, const Coordinates&);
    bool operator==(const Coordinates&) const;
};