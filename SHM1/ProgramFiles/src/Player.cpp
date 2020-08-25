#include "Player.hpp"

Player::Player(uint16_t money, Ship* ship, uint16_t availableSpace)
    : money_(money), ship_(ship), availableSpace_(availableSpace) {}

void Player::UpdateAvailableSpace() {
    uint16_t spaceWhenShipIsEmpty = ship_->GetCapacity();

    for (const auto& cargo : ship_->GetCargos()) {
        if (spaceWhenShipIsEmpty > cargo->GetAmount()) {
            spaceWhenShipIsEmpty -= cargo->GetAmount();
        } else {
            availableSpace_ = 0;

            return;
        }
    }
}

Cargo* Player::GetCargo(uint16_t index) const {
    return ship_->GetCargo(index);
}

void Player::PayCrew(uint16_t money) {
    if (money_ - money > money_) {
        money_ -= money;

        return;
    }

    money_ = 0;
}

void Player::SetMoney(uint16_t money) {
    money_ = money;
}

void Player::LoadCargoOnShip(std::unique_ptr<Cargo> cargo, uint16_t amount) {
    ship_->Load(std::move(cargo), amount);
    UpdateAvailableSpace();
}

void Player::UnloadCargoFromShip(std::unique_ptr<Cargo> cargo, uint16_t amount) {
    ship_->Unload(std::move(cargo), amount);
    UpdateAvailableSpace();
}