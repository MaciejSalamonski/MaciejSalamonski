#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string prepareStringWithPlayerResult(std::string& playerResults) {
    const char addToEndOfString = '|';
    playerResults.push_back(addToEndOfString);

    return playerResults;
}

std::vector<std::string> foo(std::string& preparedStringWithPlayerResults) {
    std::string delimiter = "|";
    size_t position = 0;
    std::string token;
    std::vector<std::string> vectorWithResultsForEachLine{};
    while ((position = preparedStringWithPlayerResults.find(delimiter)) != std::string::npos) {
        token = preparedStringWithPlayerResults.substr(0, position);
        vectorWithResultsForEachLine.push_back(token);
        preparedStringWithPlayerResults.erase(0, position + delimiter.length());
    }

    return vectorWithResultsForEachLine;
}

constexpr uint8_t STRIKE = 10;
constexpr uint8_t ZERO_POINTS = 0;

std::vector<int> bar(std::vector<std::string>& vectorWithResultsForEachLine) {
    std::vector<int> vectorWithResults;

    std::find_if(vectorWithResultsForEachLine.cbegin(), vectorWithResultsForEachLine.cend(),
                 [&vectorWithResults](std::string bowlingLineString) {
                     std::find_if(bowlingLineString.cbegin(), bowlingLineString.cend(),
                                  [&vectorWithResults, &bowlingLineString](char charackter) {
                                      if (charackter == 'X') {
                                          vectorWithResults.push_back(STRIKE);
                                          vectorWithResults.push_back(ZERO_POINTS);
                                      }

                                      if (charackter == '-') {
                                          vectorWithResults.push_back(ZERO_POINTS);
                                      }

                                      if (isdigit(charackter)) {
                                          if (bowlingLineString[1] == '/') {
                                              uint8_t firstThrow = *bowlingLineString.begin() - '0';
                                              uint8_t secondThrow = STRIKE - firstThrow;
                                              vectorWithResults.push_back(firstThrow);
                                              vectorWithResults.push_back(secondThrow);
                                              return true;
                                          }
                                          uint8_t charackterToInteger = charackter - '0';
                                          vectorWithResults.push_back(charackterToInteger);
                                      }

                                      if (isspace(charackter)) {
                                          vectorWithResults.push_back(ZERO_POINTS);
                                          vectorWithResults.push_back(ZERO_POINTS);
                                          return true;
                                      }

                                      return false;
                                  });

                     return false;
                 });

    return vectorWithResults;
}

void splitAndPrepareString(std::string& processingString, std::string& nickName, std::vector<int>& playerResult) {
    auto delimiterPosition = processingString.find_first_of(':');
    std::string playerResults = processingString.substr(++delimiterPosition),
                playerName = processingString.substr(0, delimiterPosition);
    nickName = playerName;

    std::string preparedStringWithPlayerResults = prepareStringWithPlayerResult(playerResults);
    std::vector<std::string> vectorWithResultsForEachLine = foo(preparedStringWithPlayerResults);
    playerResult = bar(vectorWithResultsForEachLine);
}

int main() {
    std::string processingString = "Michael:X|7/|9-|X|-8|8/|-6|X|X|X| |81";
    std::string nickName;
    std::vector<int> playerResult;
    splitAndPrepareString(processingString, nickName, playerResult);

    std::cout << nickName << '\n';
    for (const auto& el : playerResult) {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    return 0;
}

//Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81
//wektor [10,0,7,3,9,0,10,0,0,8,8,2,0,6,10,0,10,0,10,0,0,0,8,1]