#include "sort.hpp"

#include <algorithm>

std::deque<std::string> fillingDequeWithWordsFromForwardlist(std::forward_list<std::string>& listWithWords) {
    std::deque<std::string> dequeWithWords{};
    dequeWithWords.insert(dequeWithWords.begin(), listWithWords.begin(), listWithWords.end());

    return dequeWithWords;
}

std::deque<std::string> changingWordsToLowercase(std::deque<std::string>& dequeWithWords) {
    for (auto& word : dequeWithWords) {
        std::transform(word.begin(), word.end(), word.begin(), [](char charackter) {
            return std::tolower(charackter);
        });
    }

    return dequeWithWords;
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& listWithWords) {
    std::deque<std::string> dequeWithWords = fillingDequeWithWordsFromForwardlist(listWithWords);
    listWithWords.clear();
    changingWordsToLowercase(dequeWithWords);

    std::sort(dequeWithWords.begin(), dequeWithWords.end(), [](std::string& firstWord, std::string& secondWord) {
        if (firstWord.length() != secondWord.length()) {
            return firstWord.length() < secondWord.length();
        }
        return firstWord < secondWord;
    });

    return dequeWithWords;
}