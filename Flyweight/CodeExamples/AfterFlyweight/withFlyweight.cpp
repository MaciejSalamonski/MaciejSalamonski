#include <array>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

constexpr int arrSize = 500000;

class TreeSharedShate {
public:
    std::string name_{};
    std::string color_{};
    std::array<int, arrSize> texture_{};

    TreeSharedShate(const std::string& name, const std::string& color, const std::array<int, arrSize>& texture)
        : name_(name), color_(color), texture_(texture) {}
};

class TreeUniqueState {
    unsigned int coordX_{};
    unsigned int coordY_{};

public:
    TreeUniqueState(const unsigned int& coordX, const unsigned int& coordY)
        : coordX_(coordX), coordY_(coordY) {}
};

class Flyweight {
    std::shared_ptr<TreeSharedShate> treeSharedState_;

public:
    Flyweight(const std::shared_ptr<TreeSharedShate>& treeSharedState)
        : treeSharedState_(treeSharedState) {}

    Flyweight(const Flyweight& other)
        : treeSharedState_(other.treeSharedState_) {}
};

class FlyweightFactory {
    std::map<std::shared_ptr<TreeSharedShate>, Flyweight> flyweights_;

    std::shared_ptr<TreeSharedShate> GetKey(const TreeSharedShate& treeSharedState) const {
        return std::make_shared<TreeSharedShate>(treeSharedState.name_, treeSharedState.color_, treeSharedState.texture_);
    }

public:
    FlyweightFactory(std::initializer_list<TreeSharedShate> treeSharedState) {
        std::cout << "elo " << '\n';
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

int main() {
    auto ptr = std::make_shared<FlyweightFactory>(std::initializer_list<TreeSharedShate>{
        TreeSharedShate{"Sosna", "Zielona", {}},
        TreeSharedShate{"Brzoza", "Zolya", {}}});
    ptr->FlyweightCounter();

    return 0;
}
