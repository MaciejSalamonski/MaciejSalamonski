#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>

constexpr int arrSize = 100000;

class TreeSharedShate {
public:
    std::string name_{};
    std::string color_{};
    std::array<int, arrSize> texture_{};

    TreeSharedShate(const std::string& name, const std::string& color, const std::array<int, arrSize>& texture)
        : name_(name), color_(color), texture_(texture) {}

    friend std::ostream& operator<<(std::ostream& os, const TreeSharedShate& us) {
        return os << "[ " << us.name_ << " , " << us.color_ << " ]";
    }
};

class TreeUniqueState {
    unsigned int coordX_{};
    unsigned int coordY_{};

public:
    TreeUniqueState(const unsigned int& coordX, const unsigned int& coordY)
        : coordX_(coordX), coordY_(coordY) {}

    void fillCoords(const TreeUniqueState& us) {
        us.coordX_;
        us.coordY_;
    }

    friend std::ostream& operator<<(std::ostream& os, const TreeUniqueState& us) {
        return os << "[ " << us.coordX_ << " , " << us.coordY_ << " ]";
    }
};

class Flyweight {
    std::shared_ptr<TreeSharedShate> treeSharedState_;

public:
    Flyweight(const std::shared_ptr<TreeSharedShate>& treeSharedState)
        : treeSharedState_(treeSharedState) {}

    Flyweight(const Flyweight& other)
        : treeSharedState_(other.treeSharedState_) {}

    void Operation(const TreeUniqueState& treeUniqueState) const {
        treeUniqueState;
        std::cout << "Drzewo (" << treeSharedState_ << ") O wspolrzednych: (" << treeUniqueState << ") state.\n";
    }
};

class FlyweightFactory {
    std::map<std::shared_ptr<TreeSharedShate>, Flyweight> flyweights_;

    std::shared_ptr<TreeSharedShate> GetKey(const TreeSharedShate& treeSharedState) const {
        return std::make_shared<TreeSharedShate>(treeSharedState.name_, treeSharedState.color_, treeSharedState.texture_);
    }

public:
    FlyweightFactory(std::initializer_list<TreeSharedShate> treeSharedState) {
        for (const TreeSharedShate& el : treeSharedState) {
            this->flyweights_.insert(std::make_pair<std::shared_ptr<TreeSharedShate>, Flyweight>(
                this->GetKey(el), Flyweight(std::make_shared<TreeSharedShate>(el))));
        }
    }

    Flyweight GetFlyweight(const TreeSharedShate& treeSharedState) {
        std::shared_ptr<TreeSharedShate> key = this->GetKey(treeSharedState);
        if (this->flyweights_.find(key) == this->flyweights_.end()) {
            this->flyweights_.insert(std::make_pair(key, Flyweight(std::make_shared<TreeSharedShate>(treeSharedState))));
        }

        return this->flyweights_.at(key);
    }

    void FlyweightCounter() const {
        size_t count = this->flyweights_.size();
        std::cout << "There is " << count << " flyweights!" << '\n';
    }
};

class GenerateForest {
    std::vector<std::pair<unsigned int, unsigned int>> getPosition(const int numberOfTrees) {
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

    FlyweightFactory& factory = std::make_shared<FlyweightFactory>(std::initializer_list<TreeSharedShate>{
        TreeSharedShate{"Sosna", "Zielona", {}},
        TreeSharedShate{"Wierzba", "Czarna", {}},
        TreeSharedShate{"Brzoza", "Biala", {}}});

public:
    void addSingleTree(FlyweightFactory& ff, const std::string& name, const std::string& color, const std::array<int, arrSize>& texture, const unsigned int& coordX, const unsigned int& coordY) {
        const Flyweight& flyweight = ff.GetFlyweight(TreeSharedShate{name, color, {}});
        flyweight.Operation({coordX, coordY});
    }

    void generateForest(const std::string& name, const std::string& color, unsigned int numberOfTrees) {
        for (const auto& coordinates : getPosition(numberOfTrees)) {
            addSingleTree(factory, name, color, {}, coordinates.first, coordinates.second);
        }
    }
};

int main() {
    //auto factory = std::make_shared<FlyweightFactory>(std::initializer_list<TreeSharedShate>{
    //    TreeSharedShate{"Sosna", "Zielona", {}},
    //    TreeSharedShate{"Wierzba", "Czarna", {}},
    //    TreeSharedShate{"Brzoza", "Biala", {}}});
    //factory->FlyweightCounter();
    //
    auto forest = std::make_shared<GenerateForest>();
    forest->generateForest("Sosna", "Zielona", 200);

    return 0;
}
