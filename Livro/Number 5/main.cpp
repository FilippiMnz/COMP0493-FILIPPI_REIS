#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

void mostFrequentWord(const std::string &str) {
    std::unordered_map<std::string, int> wordCount;
    std::string word;
    std::stringstream ss(str);

    while (ss >> word) {
        wordCount[word]++;
    }

    std::string mostFrequent;
    int maxCount = 0;

    for (const auto &entry : wordCount) {
        if (entry.second > maxCount) {
            mostFrequent = entry.first;
            maxCount = entry.second;
        }
    }

    std::cout << "A palavra mais frequente é: " << mostFrequent << std::endl;
}

int main() {
    std::string TTT = "I love competitive programming. I also love algorithm.";
    mostFrequentWord(TTT);
    return 0;
}
