#include <iostream>

#include "insensitivePalindrom.hpp"

int main() {
    std::string someText = "!@#&abba%^#@![]";
    std::string anotherText = "!@#&abbca%^#@![]";
    std::cout << isPalindrome(someText) << '\n';
    std::cout << isPalindrome(anotherText) << '\n';

    return 0;
}