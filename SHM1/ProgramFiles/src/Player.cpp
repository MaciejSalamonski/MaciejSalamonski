#include "Player.hpp"

Player::Player(uint16_t money, Ship* ship, uint16_t availableSpace)
    : money_(money), ship_(ship), availableSpace_(availableSpace) {}

Cargo* Player::GetCargo(uint16_t index) const {
    return ship_->GetCargo(index);
}