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
        vectorWithResultsForEachLine.push_back(token);
        preparedStringWithPlayerResults.erase(0, position + delimiter.length());
    }

    return vectorWithResultsForEachLine;
}

constexpr uint8_t strike = 10;
constexpr uint8_t zeroPoints = 0;
constexpr char isStrike = 'X';
constexpr char isMiss = '-';
constexpr char isSpare = '/';
constexpr char convertCharToInt = '0';

std::vector<int> stringParsing(std::vector<std::string>& vectorWithResultsForEachLine) {
    std::vector<int> vectorWithResults{};

    std::find_if(vectorWithResultsForEachLine.cbegin(), vectorWithResultsForEachLine.cend(),
                 [&vectorWithResults](std::string bowlingLineString) {
                     std::find_if(bowlingLineString.cbegin(), bowlingLineString.cend(),
                                  [&vectorWithResults, &bowlingLineString](const char charackter) {
                                      if (charackter == isStrike) {
                                          vectorWithResults.push_back(strike);
                                          vectorWithResults.push_back(zeroPoints);
                                      }

                                      if (charackter == isMiss) {
                                          vectorWithResults.push_back(zeroPoints);
                                      }

                                      if (isdigit(charackter)) {
                                          if (bowlingLineString[1] == isSpare) {
                                              uint8_t firstThrow = *bowlingLineString.begin() - convertCharToInt;
                                              uint8_t secondThrow = strike - firstThrow;
                                              vectorWithResults.push_back(firstThrow);
                                              vectorWithResults.push_back(secondThrow);
                                              return true;
                                          }
                                          uint8_t charackterToInteger = charackter - convertCharToInt;
                                          vectorWithResults.push_back(charackterToInteger);
                                      }

                                      if (isspace(charackter)) {
                                          vectorWithResults.push_back(zeroPoints);
                                          vectorWithResults.push_back(zeroPoints);
                                          return true;
                                      }

                                      return false;
                                  });

                     return false;
                 });

    return vectorWithResults;
}

void stringProcessing(std::string& processingString, std::string& nickName, std::vector<int>& playerResult) {
    auto delimiterPosition = processingString.find_first_of(':');
    std::string playerResults = processingString.substr(++delimiterPosition),
                playerName = processingString.substr(0, delimiterPosition);
    nickName = playerName;

    std::string preparedStringWithPlayerResults = stringPreparing(playerResults);
    std::vector<std::string> vectorWithResultsForEachLine = stringSplitting(preparedStringWithPlayerResults);
    playerResult = stringParsing(vectorWithResultsForEachLine);
}

int main() {
    std::string processingString = "Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81";
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