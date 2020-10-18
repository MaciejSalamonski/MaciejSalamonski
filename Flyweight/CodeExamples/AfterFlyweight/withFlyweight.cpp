#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <tuple>
#include <unordered_map>
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
    TreeSharedShate* treeSharedState_;

public:
    Flyweight(const TreeSharedShate* treeSharedState)
        : treeSharedState_(new TreeSharedShate(*treeSharedState)) {}

    Flyweight(const Flyweight& other)
        : treeSharedState_(new TreeSharedShate(*other.treeSharedState_)) {}

    ~Flyweight() {
        delete treeSharedState_;
    }
    TreeSharedShate* shared_state() const {
        return treeSharedState_;
    }
    void Operation(const TreeUniqueState& treeUniqueState) const {
        treeUniqueState;
        std::cout << "Drzewo (" << *treeSharedState_ << ") O wspolrzednych: (" << treeUniqueState << ") state.\n";
    }
};

class FlyweightFactory {
    std::unordered_map<std::tuple<const std::string&, const std::string&, const std::array<int, arrSize>&>, Flyweight> flyweights_;

    std::tuple<const std::string&, const std::string&, const std::array<int, arrSize>&> GetKey(const TreeSharedShate& treeSharedState) const {
        std::tuple<const std::string&, const std::string&, const std::array<int, arrSize>&> vec{treeSharedState.name_, treeSharedState.color_, treeSharedState.texture_};

        return vec;
    }

public:
    FlyweightFactory(std::initializer_list<TreeSharedShate> treeSharedState) {
        for (const TreeSharedShate& el : treeSharedState) {
            this->flyweights_.insert(std::make_pair<std::tuple<const std::string&, const std::string&, const std::array<int, arrSize>&>, Flyweight>(
                this->GetKey(el), Flyweight(&el)));
        }
    }

    Flyweight GetFlyweight(const TreeSharedShate& treeSharedState) {
        std::tuple<const std::string&, const std::string&, const std::array<int, arrSize>&> key = this->GetKey(treeSharedState);
        if (this->flyweights_.find(key) == this->flyweights_.end()) {
            this->flyweights_.insert(std::make_pair(key, Flyweight(&treeSharedState)));
        }

        return this->flyweights_.at(key);
    }

    void FlyweightCounter() const {
        size_t count = this->flyweights_.size();
        std::cout << "There is " << count << " flyweights!" << '\n';
    }
};

//class GenerateForest {
//    std::vector<std::pair<unsigned int, unsigned int>> getPosition(const int numberOfTrees) {
//        std::vector<std::pair<unsigned int, unsigned int>> positions_;
//        std::random_device rd;
//        std::mt19937 gen(rd());
//
//        const int sizeX = 1000;
//        const int sizeY = 1000;
//
//        std::vector<unsigned int> positionX(sizeX);
//        std::vector<unsigned int> positionY(sizeY);
//
//        std::iota(positionX.begin(), positionX.end(), 0);
//        std::iota(positionY.begin(), positionY.end(), 0);
//
//        std::shuffle(positionX.begin(), positionX.end(), gen);
//        std::shuffle(positionY.begin(), positionY.end(), gen);
//
//        for (size_t i = 0; i < numberOfTrees; i++) {
//            positions_.emplace_back(std::make_pair(positionX[i], positionY[i]));
//        }
//
//        return positions_;
//    }
//
//    FlyweightFactory* factory = new FlyweightFactory({{"Sosna", "Zielona", {}}, {"Wierzba", "Czarna", {}}, {"Brzoza", "Biala", {}}});
//
//public:
//    void addSingleTree(FlyweightFactory& ff, const std::string& name, const std::string& color, const std::array<int, arrSize>& texture, const unsigned int& coordX, const unsigned int& coordY) {
//        const Flyweight& flyweight = ff.GetFlyweight(TreeSharedShate{name, color, {}});
//        flyweight.Operation({coordX, coordY});
//    }
//
//    void generateForest(const std::string& name, const std::string& color, unsigned int numberOfTrees) {
//        for (const auto& coordinates : getPosition(numberOfTrees)) {
//            addSingleTree(*factory, name, color, {}, coordinates.first, coordinates.second);
//            factory->FlyweightCounter();
//        }
//    }
//
//    ~GenerateForest() {
//        delete factory;
//    }
//};

void AddCarToPoliceDatabase(
    FlyweightFactory& ff,
    const std::string& name,
    const std::string& color,
    const std::array<int, arrSize>& texture,
    const unsigned int& coordX,
    const unsigned int& coordY) {
    std::cout << "\nClient: Adding a car to database.\n";
    const Flyweight& flyweight = ff.GetFlyweight({name, color, texture});
    flyweight.Operation({coordX, coordY});
}

int main() {
    //auto forest = std::make_shared<GenerateForest>();
    // forest->generateForest("Sosna", "Zielonaaa", 200)
    FlyweightFactory* factory = new FlyweightFactory({{"Sosna", "Zielona", {}}, {"Wierzba", "Czarna", {}}, {"Brzoza", "Biala", {}}});

    factory->FlyweightCounter();

    AddCarToPoliceDatabase(*factory,
                           "Swierk",
                           "Zielony",
                           {},
                           1,
                           2);

    AddCarToPoliceDatabase(*factory,
                           "Swierk",
                           "Papierowa",
                           {},
                           1,
                           3);

    factory->FlyweightCounter();
    delete factory;

    return 0;
}
