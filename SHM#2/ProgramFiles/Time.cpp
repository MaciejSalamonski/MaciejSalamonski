#include "Time.hpp"

#include <algorithm>

constexpr uint16_t startTime = 1;

Time::Time()
    : timeElapsed_(startTime) {}

void Time::addObserver(Observer* observer) {
    observers_.push_back(observer);
}

void Time::removeObserver(Observer* observer) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

uint16_t Time::getElapsedTime() const {
    return timeElapsed_;
}

Time& Time::operator++() {
    ++timeElapsed_;

    std::for_each(observers_.begin(), observers_.end(),
                  [](auto observer) {
                      observer->nextDay();
                  });

    return *this;
}