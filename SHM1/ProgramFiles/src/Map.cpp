#include "Map.hpp"

#include <algorithm>
#include <random>
#include <vector>

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> possiblePosX(0, MAX_VALUE_OF_AXIS_X);
    std::uniform_int_distribution<> possiblePosY(0, MAX_VALUE_OF_AXIS_Y);
    islands_.reserve(NUMBER_OF_ISLANDS);
    std::vector<std::pair<uint8_t, uint8_t>> positionBefore;
    uint8_t counter{};

    do {
        uint8_t posX = possiblePosX(gen);
        uint8_t posY = possiblePosY(gen);

        if (std::find_if(positionBefore.begin(), positionBefore.end(),
                         [posX, posY](const auto& position) {
                             return posX == position.first && posY == position.second;
                         }) == positionBefore.end()) {
            positionBefore.push_back(std::make_pair(posX, posY));
            islands_.push_back(Island(posX, posY));
            counter++;
        }

    } while (counter != NUMBER_OF_ISLANDS);

    currentPosition_ = &islands_.front();
}

uint16_t Map::GetDistanceToIsland(Island* destination) const {
    return Coordinates::Distance(destination->GetCoordinates(), GetCurrentPosition()->GetCoordinates());
}

Island* Map::GetIsland(const Coordinates& coordinates) {
    auto soughtIsland = std::find_if(islands_.begin(), islands_.end(),
                                     [coordinates](const auto& island) {
                                         return coordinates == island.GetCoordinates();
                                     });

    if (soughtIsland != islands_.end()) {
        return &*soughtIsland;
    }

    return nullptr;
}