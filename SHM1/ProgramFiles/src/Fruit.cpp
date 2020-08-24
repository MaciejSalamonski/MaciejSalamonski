#include "Fruit.hpp"

Fruit::Fruit(uint16_t amount, const std::string& name, uint16_t basePrice, uint8_t timeElapsed, uint8_t expiryDate)
    : Cargo(amount, name, basePrice_), timeElapsed_(timeElapsed), expiryDate_(expiryDate) {}

uint16_t Fruit::GetPrice() const {
    return static_cast<uint16_t>(std::floor(GetBasePrice() * (float(GetTimeElapsed()) / GetExpiryDate())));
}

Cargo& Fruit::operator+=(uint16_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(uint16_t amount) {
    if (amount_ - amount > amount_) {
        return *this;
    }

    amount_ -= amount;
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    if (typeid(*this) == typeid(cargo)) {
        return cargo.GetName() == name_ &&
               cargo.GetBasePrice() == basePrice_ &&
               cargo.GetPrice() == GetPrice() &&
               cargo.GetAmount() == amount_;
    }

    return false;
}