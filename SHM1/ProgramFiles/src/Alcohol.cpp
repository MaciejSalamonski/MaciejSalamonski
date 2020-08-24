#include "Alcohol.hpp"

Alcohol::Alcohol(uint16_t amount, const std::string& name, uint16_t basePrice, uint8_t percentage)
    : Cargo(amount, name, basePrice), percentage_(percentage) {}

uint16_t Alcohol::GetPrice() const {
    return static_cast<uint16_t>(std::floor(GetBasePrice() * GetPercentage() / MAX_ALCOHOL_POWER));
}

Cargo& Alcohol::operator+=(uint16_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(uint16_t amount) {
    if (amount_ - amount > amount_) {
        return *this;
    }

    amount_ -= amount;
    return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    if (typeid(*this) == (typeid(cargo))) {
        return cargo.GetName() == name_ &&
               cargo.GetBasePrice() == basePrice_ &&
               cargo.GetPrice() == GetPrice() &&
               cargo.GetAmount() == GetAmount();
    }
    return false;
}
