#pragma once

#include <string>
#include <vector>

#include "Cargo.hpp"
#include "Player.hpp"

class Ship : public Observer {
    uint16_t id_;
    std::string name_;
    uint16_t speed_;
    uint16_t crew_;
    uint16_t maxCrew_;
    uint16_t capacity_;
    Delegate* delegate_;
    std::vector<Cargo*> cargos_;

public:
    Ship();
    Ship(uint16_t, const std::string&, uint16_t, Delegate*, uint16_t, uint16_t);
    Ship(uint16_t, uint16_t, uint16_t);

    uint16_t getId() const;
    std::string getName() const;
    uint16_t getSpeed() const;
    uint16_t getCrew() const;
    uint16_t getMaxCrew() const;
    uint16_t getCapacity() const;
    Cargo* getCargo(uint16_t) const;
    std::vector<Cargo*> getCargos() const;

    void setName(const std::string&);

    Ship& operator+=(const uint16_t);
    Ship& operator-=(const uint16_t);

    // Override from Observer
    void nextDay() override;
};