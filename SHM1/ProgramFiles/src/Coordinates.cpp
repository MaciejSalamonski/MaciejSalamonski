#include "Coordinates.hpp"

Coordinates::Coordinates(uint8_t positionX, uint8_t positionY)
    : positionX_(positionX), positionY_(positionY) {}

uint16_t Coordinates::Distance(const Coordinates& lhs, const Coordinates& rhs) {
    uint8_t distanceX = std::max(lhs.GetPositionX(), rhs.GetPositionX()) - std::min(lhs.GetPositionX(), rhs.GetPositionX());
    uint8_t distanceY = std::max(lhs.GetPositionY(), rhs.GetPositionY()) - std::min(lhs.GetPositionY(), rhs.GetPositionY());

    return static_cast<uint16_t>(std::floor(std::hypot(distanceX, distanceY)));
}

bool Coordinates::operator==(const Coordinates& coords) const {
    if (typeid(*this) == typeid(coords)) {
        return coords.GetPositionX() == positionX_ &&
               coords.GetPositionY() == positionY_;
    }

    return false;
}