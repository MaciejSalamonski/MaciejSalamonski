#include "Coordinates.hpp"

Coordinates::Coordinates(uint16_t positionX, uint16_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

uint16_t Coordinates::getPositionX() const {
    return positionX_;
}

uint16_t Coordinates::getPositionY() const {
    return positionY_;
}

bool Coordinates::operator==(const Coordinates& coordinates) const {
    return coordinates.getPositionX() == positionX_ && coordinates.getPositionY() == positionY_;
}

std::ostream& operator<<(std::ostream& out, const Coordinates& coordinates) {
    out << "Coordinates: [" << std::setw(2) << coordinates.positionX_ << ", " << std::setw(2) << coordinates.positionY_ << "]";

    return out;
}