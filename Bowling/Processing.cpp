#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81
//wektor [10,0,7,3,9,0,10,0,0,8,8,2,0,6,10,0,10,0,10,0,0,0,8,1]

std::string prepareStringWithPlayerResult(std::string& playerResults) {
    const char addToEndOfString = '|';
    playerResults.push_back(addToEndOfString);

    return playerResults;
}

std::vector<std::string> foo(std::string& preparedStringWithPlayerResults) {
    std::string delimiter = "|";
    size_t pos = 0;
    std::string token;
    std::vector<std::string> vectorWithResultsForEachLine{};
    while ((pos = preparedStringWithPlayerResults.find(delimiter)) != std::string::npos) {
        token = preparedStringWithPlayerResults.substr(0, pos);
        vectorWithResultsForEachLine.push_back(token);
        preparedStringWithPlayerResults.erase(0, pos + delimiter.length());
    }

    return vectorWithResultsForEachLine;
}

std::vector<int> bar(std::vector<std::string>& vectorWithResultsForEachLine) {
    std::vector<int> vectorWithResults;

    std::find_if(vectorWithResultsForEachLine.cbegin(), vectorWithResultsForEachLine.cend(),
                 [&vectorWithResults](std::string sentence) {
                     std::find_if(sentence.begin(), sentence.end(),
                                  [&vectorWithResults, &sentence](char charackter) {
                                      if (charackter == 'X') {
                                          vectorWithResults.push_back(10);
                                          vectorWithResults.push_back(0);
                                      }

                                      if (charackter == '-') {
                                          vectorWithResults.push_back(0);
                                      }

                                      if (charackter == '\0') {
                                          vectorWithResults.push_back(0);
                                          vectorWithResults.push_back(0);
                                          return true;
                                      }

                                      if (isdigit(charackter)) {
                                          if (sentence[1] == '/') {
                                              int x = *sentence.begin() - '0';
                                              vectorWithResults.push_back(x);
                                              int y = 10;
                                              int z = y - x;
                                              vectorWithResults.push_back(z);
                                              return true;
                                          }
                                          int xd = charackter - '0';
                                          vectorWithResults.push_back(xd);
                                      }

                                      if (isspace(charackter)) {
                                          vectorWithResults.push_back(0);
                                          vectorWithResults.push_back(0);
                                          return true;
                                      }

                                      return false;
                                  });
                     return false;
                 });

    return vectorWithResults;
}

void splitAndPrepareString(std::string& processingString, std::map<std::string, std::vector<std::string>>& mapWithPlayerNameAndResult) {
    auto delimiterPosition = processingString.find_first_of(':');
    std::string playerResults = processingString.substr(++delimiterPosition),
                playerName = processingString.substr(0, delimiterPosition);

    std::string preparedStringWithPlayerResults = prepareStringWithPlayerResult(playerResults);
    std::vector<std::string> vectorWithResultsForEachLine = foo(preparedStringWithPlayerResults);
    std::vector<int> preparedVectroWithResultsForEachLine = bar(vectorWithResultsForEachLine);

    for (const auto& el : preparedVectroWithResultsForEachLine) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    //
    //for (const auto& el : vectorWithResultsForEachLine) {
    //    std::cout << el << " ";
    //}
    //std::cout << '\n';
    // mapWithPlayerNameAndResult.insert(std::pair<std::string, std::string>(playerName, playerResults));
}

int main() {
    std::string processingString = "Michael:X|7/|9-|X|-8|8/|-6|X|X|X| |81";
    std::string string = "RACHEL:5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5";
    std::map<std::string, std::vector<std::string>> mapWithPlayerNameAndResult;
    splitAndPrepareString(processingString, mapWithPlayerNameAndResult);

    return 0;
}
