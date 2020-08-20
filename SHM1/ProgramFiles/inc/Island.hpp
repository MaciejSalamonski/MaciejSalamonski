#pragma once

#include "Coordinates.hpp"

class Island {
    Coordinates position_;

public:
    Island(uint16_t, uint16_t);
    Coordinates GetCoordinates() const;
};