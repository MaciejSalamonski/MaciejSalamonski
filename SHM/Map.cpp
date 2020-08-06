#include "Map.hpp"

#include <algorithm>
#include <random>

constexpr uint16_t islandsAmount = 10;
constexpr uint16_t axisX = 100;
constexpr uint16_t axisY = 100;

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> generatePosX(0, axisX);
    std::uniform_int_distribution<> generatePosY(0, axisY);
    std::vector<std::pair<uint16_t, uint16_t>> positionInPast;
    islands_.reserve(islandsAmount);
    uint16_t counter{};

    do {
        uint16_t positionX = generatePosX(gen);
        uint16_t positionY = generatePosY(gen);

        if (std::find_if(positionInPast.begin(), positionInPast.end(),
                         [positionX, positionY](const auto& position) {
                             return position.first == positionX && position.second == positionY;
                         }) == positionInPast.end()) {
            positionInPast.push_back(std::make_pair(positionX, positionY));
            islands_.push_back(Island(positionX, positionY));
            counter++;
        }

    } while (counter != islandsAmount);

    currentPosition_ = &islands_.front();
}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto soughtIsland = std::find_if(islands_.begin(), islands_.end(),
                                     [&coordinates](auto islandPosition) {
                                         return coordinates == islandPosition.getPosition();
                                     });
    if (soughtIsland != islands_.end()) {
        return &*soughtIsland;
    }
    return nullptr;
}