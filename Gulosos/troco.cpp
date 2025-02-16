#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector<int> problemaDoTroco(vector<int> &moedas, int valor) {
    sort(moedas.rbegin(), moedas.rend());
    vector<int> resultado;
    for (int moeda : moedas) {
        while (valor >= moeda) {
            valor -= moeda;
            resultado.push_back(moeda);
        }
    }
    return resultado;
}
