#include <iostream>
#include <cctype>
#include <string>

void analyzeString(const std::string &str) {
    int digits = 0, vowels = 0, consonants = 0;

    for (char ch : str) {
        ch = std::tolower(ch);
        if (std::isdigit(ch)) {
            digits++;
        } else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else if (std::isalpha(ch)) {
            consonants++;
        }
    }

    std::cout << "Dígitos: " << digits << std::endl;
    std::cout << "Vogais: " << vowels << std::endl;
    std::cout << "Consoantes: " << consonants << std::endl;
}

int main() {
    std::string TTT = "I love CS3233 Competitive Programming!";
    analyzeString(TTT);
    return 0;
}
