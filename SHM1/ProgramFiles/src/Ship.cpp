#include "Ship.hpp"

#include <algorithm>
#include <iostream>

Ship::Ship(uint16_t capacity, uint16_t crew, uint16_t speed, const std::string& name, uint16_t id)
    : capacity_(capacity), crew_(crew), speed_(speed), name_(name), id_(id) {}

std::vector<std::unique_ptr<Cargo>>::iterator Ship::FindMatchCargo(Cargo* cargo) {
    auto findMatchCargo = std::find_if(cargo_.begin(), cargo_.end(),
                                       [cargo](const auto& findCargo) {
                                           return cargo->GetName() == findCargo->GetName() &&
                                                  cargo->GetPrice() == findCargo->GetPrice() &&
                                                  cargo->GetBasePrice() == findCargo->GetBasePrice();
                                       });

    return findMatchCargo;
}

void Ship::RemoveFromStorage(Cargo* cargo) {
    cargo_.erase(FindMatchCargo(cargo));
}

void Ship::Load(std::unique_ptr<Cargo> cargo, uint16_t amount) {
    uint16_t amountSum{};

    std::for_each(cargo_.begin(), cargo_.end(),
                  [&amountSum](const auto& elem) {
                      amountSum += elem->GetAmount();
                  });

    if (amountSum > GetCapacity()) {
        std::cerr << "You can't load these cargo!. Maximum capacity of your ship is: " << GetCapacity() << '\n';
        return;
    }

    auto IsCargoUnique = FindMatchCargo(cargo.get());

    if (IsCargoUnique == cargo_.end()) {
        cargo_.push_back(std::move(cargo));

        return;
    }

    **IsCargoUnique += amount;
}

void Ship::Unload(std::unique_ptr<Cargo> cargo, uint16_t amount) {
    auto choosenCargo = FindMatchCargo(cargo.get());

    if (choosenCargo == cargo_.end()) {
        return;
    }

    if ((*choosenCargo)->GetAmount() <= cargo->GetAmount()) {
        RemoveFromStorage(cargo.get());
        return;
    }

    **choosenCargo -= amount;
}

Cargo* Ship::GetCargo(uint16_t index) const {
    if (index < cargo_.size()) {
        return cargo_[index].get();
    }

    return nullptr;
}

void Ship::NextDay() {
    delegate_->PayCrew(crew_);
}