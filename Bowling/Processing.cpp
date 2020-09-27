#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string stringPreparing(std::string& playerResults) {
    const char addToEndOfString = '|';
    playerResults.push_back(addToEndOfString);

    return playerResults;
}

std::vector<std::string> stringSplitting(std::string& preparedStringWithPlayerResults) {
    const std::string delimiter = "|";
    size_t position = 0;
    std::string token;
    std::vector<std::string> vectorWithResultsForEachLine{};
    while ((position = preparedStringWithPlayerResults.find(delimiter)) != std::string::npos) {
        token = preparedStringWithPlayerResults.substr(0, position);
        vectorWithResultsForEachLine.emplace_back(token);
        preparedStringWithPlayerResults.erase(0, position + delimiter.length());
    }

    return vectorWithResultsForEachLine;
}

namespace {
constexpr uint8_t strike = 10;
constexpr uint8_t zeroPoints = 0;
constexpr char isStrike = 'X';
constexpr char isMiss = '-';
constexpr char isSpare = '/';
constexpr char convertCharToInt = '0';
constexpr uint8_t addZeroPointsToVectorEndForThisSize = 25;
}  // namespace

std::vector<int> stringParsing(std::vector<std::string>& vectorWithResultsForEachLine) {
    std::vector<int> vectorWithResults{};

    std::find_if(vectorWithResultsForEachLine.cbegin(), vectorWithResultsForEachLine.cend(),
                 [&vectorWithResults](std::string bowlingLineString) {
                     std::find_if(bowlingLineString.cbegin(), bowlingLineString.cend(),
                                  [&vectorWithResults, &bowlingLineString](const char charackter) {
                                      if (charackter == isStrike) {
                                          vectorWithResults.emplace_back(strike);
                                          vectorWithResults.emplace_back(zeroPoints);
                                      }

                                      if (charackter == isMiss) {
                                          vectorWithResults.emplace_back(zeroPoints);
                                      }

                                      if (isdigit(charackter)) {
                                          if (bowlingLineString[1] == isSpare) {
                                              uint8_t firstThrow = *bowlingLineString.begin() - convertCharToInt;
                                              uint8_t secondThrow = strike - firstThrow;
                                              vectorWithResults.emplace_back(firstThrow);
                                              vectorWithResults.emplace_back(secondThrow);
                                              return true;
                                          }
                                          uint8_t charackterToInteger = charackter - convertCharToInt;
                                          vectorWithResults.emplace_back(charackterToInteger);
                                      }

                                      return false;
                                  });

                     return false;
                 });

    if (vectorWithResults.size() == addZeroPointsToVectorEndForThisSize) {
        vectorWithResults.emplace_back(zeroPoints);
    }

    return vectorWithResults;
}

void stringProcessing(std::string& processingString, std::string& nickName, std::vector<int>& playerResult) {
    auto delimiterPosition = processingString.find_first_of(':');
    std::string playerResults = processingString.substr(++delimiterPosition),
                playerName = processingString.substr(0, --delimiterPosition);
    nickName = playerName;

    std::string preparedStringWithPlayerResults = stringPreparing(playerResults);
    std::vector<std::string> vectorWithResultsForEachLine = stringSplitting(preparedStringWithPlayerResults);
    playerResult = stringParsing(vectorWithResultsForEachLine);
}

int main() {
    std::string processingString = "Michael:X|7/|9-|X|-8|8/|-6|X|X|X||X53";
    std::string nickName;
    std::vector<int> playerResult;
    stringProcessing(processingString, nickName, playerResult);

    std::cout << nickName << '\n';
    for (const auto& el : playerResult) {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    return 0;
}