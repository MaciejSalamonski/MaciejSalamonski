#include "Ship.hpp"

#include <iostream>

Ship::Ship()
    : id_(-1) {}
Ship::Ship(uint16_t id, const std::string& name, uint16_t speed, uint16_t maxCrew, uint16_t capacity, uint16_t crew)
    : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity), crew_(crew) {}
Ship::Ship(uint16_t id, uint16_t speed, uint16_t maxCrew)
    : Ship(id, "", speed, maxCrew, 0, 0) {}

Ship& Ship::operator+=(const uint16_t newCrewMembers) {
    if (crew_ + newCrewMembers > maxCrew_) {
        std::cerr << "The number of crew members cannot be greater than: " << maxCrew_ << "!" << '\n';
        return *this;
    }
    crew_ += newCrewMembers;
    return *this;
}

Ship& Ship::operator-=(const uint16_t retiredCrewMembers) {
    if (crew_ - retiredCrewMembers > crew_) {
        std::cerr << "The number of crew members cannot be less than zero!" << '\n';
        return *this;
    }
    crew_ -= retiredCrewMembers;
    return *this;
}

uint16_t Ship::getId() const {
    return id_;
}
std::string Ship::getName() const {
    return name_;
}
uint16_t Ship::getSpeed() const {
    return speed_;
}
uint16_t Ship::getMaxCrew() const {
    return maxCrew_;
}
uint16_t Ship::getCapacity() const {
    return capacity_;
}
uint16_t Ship::getCrew() const {
    return crew_;
}

void Ship::setName(const std::string& name) {
    name_ = name;
}
