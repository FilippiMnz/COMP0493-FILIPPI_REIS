#include <stdio.h> //C input output
#include <iostream> //C++ input output
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

long long Fat(int N, int K){
    long long resultado = 1;
    while(N >0){
        resultado *= N;
        N -= K;
    }
    return resultado;
}

int main() {
    int T; // Numero de chamadas
    cin >> T;
    vector<long long> resultados;
    for(int i = 0; i < T; i++){
        string entrada;
        cin >> entrada;

        size_t posisao = entrada.find('!');
        int N = stoi(entrada.substr(0, posisao));
        int K = entrada.length() - posisao;

        if(N >= 1 && N <= 100 && K >= 1 && K <= 20){
            resultados.push_back(Fat(N,K));
        }else{
            resultados.push_back(-1);
        }
    }

    for(long long resultado : resultados){
        if(resultado != -1){
            cout << resultado << endl;
        }else{
            
        }
    }
    return 0;
}