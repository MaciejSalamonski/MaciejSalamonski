#include "Map.hpp"

#include <algorithm>
#include <cmath>
#include <random>

constexpr uint8_t islandsAmount = 10;
constexpr uint16_t axisX = 100;
constexpr uint16_t axisY = 100;

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> genPositionX(0, axisX);
    std::uniform_int_distribution<> genPositionY(0, axisY);
    islands_.reserve(islandsAmount);
    uint8_t counter{};
    std::vector<std::pair<uint16_t, uint16_t>> positionBefore;

    do {
        uint16_t genPosX = genPositionX(gen);
        uint16_t genPosY = genPositionY(gen);

        if (std::find_if(positionBefore.begin(), positionBefore.end(),
                         [genPosX, genPosY](const auto& position) {
                             return position.first == genPosX && position.second == genPosY;
                         }) == positionBefore.end()) {
            positionBefore.push_back(std::make_pair(genPosX, genPosY));
            islands_.push_back(Island(genPosX, genPosY));
            counter++;
        }

    } while (counter != islandsAmount);

    currentPosition_ = &islands_.front();
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto soughtIsland = std::find_if(islands_.begin(), islands_.end(),
                                     [&coordinate](const auto positionX, const auto positionY) {
                                         return coordinate.getPositionX() == positionX && coordinate.getPositionY() == positionY;
                                     });

    if (soughtIsland != islands_.end()) {
        return &*soughtIsland;
    }
    return nullptr;
}

uint16_t Map::getDistanceToIsland(Island* destination) const {
    uint16_t currentPosX = currentPosition_->getPosition().getPositionX();
    uint16_t currentPosY = currentPosition_->getPosition().getPositionY();

    uint16_t destinationPosX = destination->getPosition().getPositionX();
    uint16_t destinationPosY = destination->getPosition().getPositionY();

    uint16_t distanceX = std::max(currentPosX, destinationPosX) - std::min(currentPosX, destinationPosX);
    uint16_t distanceY = std::max(currentPosY, destinationPosY) - std::min(currentPosY, destinationPosY);

    return static_cast<uint16_t>(std::floor(std::hypot(distanceX, distanceY)));
}