#include "Ship.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship()
    : id_(-1) {}

Ship::Ship(uint16_t id, const std::string& name, uint16_t speed, Delegate* delegate, uint16_t maxCrew, uint16_t capacity)
    : id_(id), name_(name), speed_(speed), delegate_(delegate), maxCrew_(maxCrew), capacity_(capacity) {}

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

void Ship::nextDay() {
    delegate_->payCrew(crew_);
}

void Ship::load(std::shared_ptr<Cargo> cargo) {
    uint16_t sumAmount{};

    for (const auto& el : cargos_) {
        sumAmount += el->getAmount();
    }

    if (sumAmount > getCapacity()) {
        std::cerr << "Our ship is to small to cary all the cargos, Captain!";
        return;
    }

    auto isCargoUnique = std::find_if(cargos_.begin(), cargos_.end(),
                                      [cargo](const auto& el) {
                                          return cargo->getBasePrice() == el->getBasePrice() &&
                                                 cargo->getPrice() == el->getPrice() &&
                                                 cargo->getName() == el->getName()
                                      });

    if (isCargoUnique == cargos_.end()) {
        cargos_.push_back(cargo);
        return;
    }

    **isCargoUnique += cargo->getAmount();
}

void unload(Cargo*) {
}