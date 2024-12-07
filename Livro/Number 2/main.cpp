#include <iostream>
#include <string>
#include <vector>

std::vector<int> findOccurrences(const std::string& T, const std::string& P) {
    std::vector<int> indices;
    size_t pos = T.find(P, 0);

    while (pos != std::string::npos) {
        indices.push_back(pos);
        pos = T.find(P, pos + 1);
    }

    if (indices.empty()) {
        indices.push_back(-1);
    }

    return indices;
}

int main() {
    std::string T, P;

    std::cout << "Digite a string T: ";
    std::getline(std::cin, T);

    std::cout << "Digite a string P: ";
    std::getline(std::cin, P);

    std::vector<int> result = findOccurrences(T, P);

    std::cout << "Índices encontrados: ";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
