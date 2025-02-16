#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Item {
    double valor, peso;
    Item(double v, double p) : valor(v), peso(p) {}
};

bool comparar(Item a, Item b) {
    return (a.valor / a.peso) > (b.valor / b.peso);
}

double mochilaFracionaria(vector<Item> &itens, double capacidade) {
    sort(itens.begin(), itens.end(), comparar);
    double valorTotal = 0.0;
    for (auto &item : itens) {
        if (capacidade >= item.peso) {
            capacidade -= item.peso;
            valorTotal += item.valor;
        } else {
            valorTotal += item.valor * (capacidade / item.peso);
            break;
        }
    }
    return valorTotal;
}