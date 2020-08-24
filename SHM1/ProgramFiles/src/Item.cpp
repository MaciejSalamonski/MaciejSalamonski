#include "Item.hpp"

Item::Item(uint16_t amount, const std::string& name, uint16_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice), rarity_(rarity) {}

uint16_t Item::GetPrice() const {
    return GetBasePrice() * static_cast<uint16_t>(GetRarity());
}

Cargo& Item::operator+=(uint16_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(uint16_t amount) {
    if (amount_ - amount > amount_) {
        return *this;
    }

    amount_ -= amount;
    return *this;
}

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(*this) == typeid(cargo)) {
        return cargo.GetName() == name_ &&
               cargo.GetPrice() == GetPrice() &&
               cargo.GetBasePrice() == basePrice_ &&
               cargo.GetAmount() == amount_;
    }

    return false;
}
