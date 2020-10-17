#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

constexpr int sizeX = 1000;
constexpr int sizeY = 1000;

int main() {
    std::vector<std::pair<unsigned int, unsigned int>> positions_;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<unsigned int> positionX(sizeX);
    std::vector<unsigned int> positionY(sizeY);

    std::iota(positionX.begin(), positionX.end(), 0);
    std::iota(positionY.begin(), positionY.end(), 0);

    std::shuffle(positionX.begin(), positionX.end(), gen);
    std::shuffle(positionY.begin(), positionY.end(), gen);

    for (int i = 0; i < 200; i++) {
        positions_.emplace_back(std::make_pair(positionX[i], positionY[i]));
    }

    for (const auto& el : positions_) {
        std::cout << el.first << " " << el.second << '\n';
    }

    return 0;
}
