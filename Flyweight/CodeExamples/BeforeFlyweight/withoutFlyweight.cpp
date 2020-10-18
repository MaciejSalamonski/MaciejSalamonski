#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

constexpr int arrSize = 100000;

class Tree {
    unsigned int coordX_{};
    unsigned int coordY_{};
    std::string name_{};
    std::string color_{};
    std::array<int, arrSize> texture_{};

public:
    Tree(const unsigned int& coordX, const unsigned int& coordY, const std::string& name, const std::string& color, const std::array<int, arrSize>& texture)
        : coordX_(coordX), coordY_(coordY), name_(name), color_(color), texture_(texture) {}
};

class GenerateForest {
    std::vector<std::shared_ptr<Tree>> forest_{};

    std::vector<std::pair<unsigned int, unsigned int>> getPosition(const unsigned int numberOfTrees) {
        std::vector<std::pair<unsigned int, unsigned int>> positions_;
        std::random_device rd;
        std::mt19937 gen(rd());

        const int sizeX = 1000;
        const int sizeY = 1000;

        std::vector<unsigned int> positionX(sizeX);
        std::vector<unsigned int> positionY(sizeY);

        std::iota(positionX.begin(), positionX.end(), 0);
        std::iota(positionY.begin(), positionY.end(), 0);

        std::shuffle(positionX.begin(), positionX.end(), gen);
        std::shuffle(positionY.begin(), positionY.end(), gen);

        for (size_t i = 0; i < numberOfTrees; i++) {
            positions_.emplace_back(std::make_pair(positionX[i], positionY[i]));
        }

        return positions_;
    }

public:
    void generateForest(const std::string& name, const std::string& color, unsigned int numberOfTrees) {
        for (const auto& coordinates : getPosition(numberOfTrees)) {
            forest_.emplace_back(std::make_shared<Tree>(Tree{coordinates.first, coordinates.second, name, color, {}}));
            std::cout << name << " " << color << ":"
                      << " Wspolrzedna X: " << coordinates.first
                      << " Wspolrzedna Y: " << coordinates.second
                      << '\n';
        }
    }
};

int main() {
    auto forest = std::make_shared<GenerateForest>();
    forest->generateForest("Sosna", "Zielona", 200);

    return 0;
}
