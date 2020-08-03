#include "removeVowels.hpp"

#include <algorithm>
#include <array>

constexpr int numberOfVowels = 12;
constexpr std::array<char, numberOfVowels> vowelsArr{
    'a', 'e', 'i', 'u', 'y', 'o', 'A', 'E', 'I', 'U', 'Y', 'O'};

void removeVowels(std::vector<std::string>& sentenceVector) {
    for (auto& sentence : sentenceVector) {
        auto remove = std::remove_if(sentence.begin(), sentence.end(),
                                     [](char vowel) {
                                         if (std::find(vowelsArr.begin(), vowelsArr.end(), vowel) != vowelsArr.end()) {
                                             return true;
                                         }

                                         return false;
                                     });
        sentence.erase(remove, sentence.end());
    }
}