#include "Ship.hpp"

#include <iostream>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(uint16_t id, const std::string& name, uint16_t speed, uint16_t crew, uint16_t maxCrew, uint16_t capacity)
    : id_(id), name_(name), speed_(speed), crew_(crew), maxCrew_(maxCrew), capacity_(capacity) {}

Ship::Ship(uint16_t id, uint16_t speed, uint16_t maxCrew)
    : Ship(id, "", speed, 0, maxCrew, 0) {}

uint16_t Ship::getId() const {
    return id_;
}
std::string Ship::getName() const {
    return name_;
}
uint16_t Ship::getSpeed() const {
    return speed_;
}
uint16_t Ship::getCrew() const {
    return crew_;
}
uint16_t Ship::getMaxCrew() const {
    return maxCrew_;
}
uint16_t Ship::getCapacity() const {
    return capacity_;
}
Cargo* Ship::getCargo(uint16_t index) const {
    return cargos_[index];
}

std::vector<Cargo*> Ship::getCargos() const {
    return cargos_;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator+=(const uint16_t newCrewMembers) {
    if (crew_ + newCrewMembers > maxCrew_) {
        std::cerr << "To many crew members! Maximum amount of crew mebers is: " << maxCrew_ << '\n';
        return *this;
    }
    crew_ += newCrewMembers;
    return *this;
}

Ship& Ship::operator-=(const uint16_t retiredCrewMembers) {
    if (crew_ - retiredCrewMembers > crew_) {
        std::cerr << "You can't retire that many members of a crew! Minimum amount of crew is 0!" << '\n';
        return *this;
    }
    crew_ -= retiredCrewMembers;
    return *this;
}