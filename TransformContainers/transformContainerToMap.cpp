#include "transformContainerToMap.hpp"

#include <algorithm>
#include <iostream>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    std::map<int, std::string> transformToMap{};

    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());

    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::transform(deque.begin(), deque.end(), list.begin(),
                   std::inserter(transformToMap, transformToMap.end()),
                   [](const int key, const std::string& value) {
                       return std::make_pair(key, value);
                   });

    return transformToMap;
}