#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt"); 
    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }

    std::string T;        
    std::string line;     
    bool firstLine = true; 

    while (std::getline(inputFile, line)) {
        
        if (line.substr(0, 7) == ".......") {
            break; 
        }
        
        if (!firstLine) {
            T += " ";
        }
        T += line;
        firstLine = false; 
    }

    inputFile.close(); 

    std::cout << "String concatenada: " << T << std::endl;

    return 0;
}
