#include "Cargo.hpp"

Cargo::Cargo(const std::string& name, uint16_t amount, uint16_t basePrice)
    : name_(name), amount_(amount), basePrice_(basePrice) {}

std::string Cargo::getName() const {
    return name_;
}

uint16_t Cargo::getAmount() const {
    return amount_;
}
uint16_t Cargo::getBasePrice() const {
    return basePrice_;
}

Cargo& Cargo::operator+=(const uint16_t newCargo) {
    amount_ += newCargo;
    return *this;
}

Cargo& Cargo::operator-=(const uint16_t deletedCargo) {
    if (amount_ - deletedCargo > amount_) {
        return *this;
    }
    amount_ -= deletedCargo;
    return *this;
}

bool Cargo::operator==(const Cargo& cargo) const {
    return cargo.getBasePrice() == basePrice_ && cargo.getName() == name_;
}