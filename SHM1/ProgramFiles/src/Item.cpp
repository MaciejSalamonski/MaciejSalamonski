#include "Item.hpp"

Item::Item(uint16_t amount, const std::string& name, uint16_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice), rarity_(rarity) {}

Rarity Item::GetRarity() const {
    return rarity_;
}

uint16_t Item::GetPrice() const {
    return GetBasePrice() * static_cast<uint16_t>(GetRarity());
}

std::string Item::GetName() const {
    return name_;
}

uint16_t Item::GetAmount() const {
    return amount_;
}

uint16_t Item::GetBasePrice() const {
    return basePrice_;
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
