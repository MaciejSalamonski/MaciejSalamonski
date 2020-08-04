#include "insensitivePalindrom.hpp"

#include <algorithm>

std::string preparingString(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(),
                             [](auto charackter) {
                                 return (isalpha(charackter) ? false : true);
                             }),
              str.end());

    std::transform(str.begin(), str.end(), str.begin(),
                   [](auto charackter) {
                       return tolower(charackter);
                   });

    return str;
}

bool isPalindrome(std::string str) {
    std::string prepStr = preparingString(str);

    return std::equal(prepStr.cbegin(), prepStr.cbegin() + prepStr.size() / 2, prepStr.crbegin());
}