#pragma once

#include "Coordinates.hpp"

class Island {
    Coordinates position_;

public:
    Island(uint8_t, uint8_t);
    Coordinates GetCoordinates() const { return position_; }
};