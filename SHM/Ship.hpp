#pragma once

#include <string>

class Ship {
    uint16_t id_;
    std::string name_;
    uint16_t speed_;
    uint16_t maxCrew_;
    uint16_t capacity_;
    uint16_t crew_;

public:
    Ship();
    Ship(uint16_t, const std::string&, uint16_t, uint16_t, uint16_t, uint16_t);
    Ship(uint16_t, uint16_t, uint16_t);

    Ship& operator+=(const uint16_t);
    Ship& operator-=(const uint16_t);

    uint16_t getId() const;
    std::string getName() const;
    uint16_t getSpeed() const;
    uint16_t getMaxCrew() const;
    uint16_t getCapacity() const;
    uint16_t getCrew() const;

    void setName(const std::string&);
};