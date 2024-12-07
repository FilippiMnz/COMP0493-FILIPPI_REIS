#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

map<int, int> Comida;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Comida.clear();

        for (int j = 0; j < n; ++j) {
            int type, Consumo;
            cin >> type >> Consumo;

            auto it = Comida.find(type);
            if (it == Comida.end()) {
                Comida[type] = Consumo;
            } else if (it->second >= 10 && it->second <= 100) {
                if (Consumo >= 10 && Consumo <= 100 && it->second < Consumo) {
                    Comida[type] = Consumo;
                }
            } else if (Consumo >= 10 && Consumo <= 100) {
                Comida[type] = Consumo;
            } else if (it->second < Consumo) {
                Comida[type] = Consumo;
            }
        }

        int amount = 0;
        for (const auto &entry : Comida) {
            amount += entry.second;
        }

        cout << amount << '\n';
    }

    return 0;
}
