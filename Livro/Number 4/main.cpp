#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

void tokenizeString(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);
    
    while (std::getline(ss, token, ' ')) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    std::sort(tokens.begin(), tokens.end());

    std::cout << "Tokens ordenados lexicograficamente: ";
    for (const std::string &t : tokens) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string TTT = "I love CS3233 competitive programming. I also love algorithm.";
    tokenizeString(TTT);
    return 0;
}
