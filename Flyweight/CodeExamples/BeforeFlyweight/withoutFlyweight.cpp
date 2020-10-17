#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

constexpr int arrSize = 1000000;
constexpr int numberOfTrees = 200;

class Tree {
    int coordX_{};
    int coordY_{};
    std::string name_{};
    std::string color_{};
    std::array<int, arrSize> texture_{};

public:
    Tree(const int& coordX, const int& coordY, const std::string& name, const std::string& color, const std::array<int, arrSize>& texture)
        : coordX_(coordX), coordY_(coordY), name_(name), color_(color), texture_(texture) {}
};

class PlantTrees {
    std::vector<std::shared_ptr<Tree>> forest_{};

public:
    void plantTree() {
        forest_.emplace_back(std::make_shared<Tree>(Tree{1, 2, "Sosna", "Zielona", {}}));
        std::cout << "Sadzimy zielona sosne!" << '\n';
    }
};

int main() {
    auto plantTrees = std::make_shared<PlantTrees>();
    for (int i = 0; i < numberOfTrees; i++) {
        plantTrees->plantTree();
    }

    return 0;
}