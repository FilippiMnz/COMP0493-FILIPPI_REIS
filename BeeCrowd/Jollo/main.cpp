#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string Entrada;

    while (getline(cin, Entrada)) {
        if (Entrada == "0 0 0 0 0") break;

        stringstream ss(Entrada);
        int a, b, c, x, y;
        ss >> a >> b >> c >> x >> y;

        vector<bool> baralho(52, false);
        baralho[a - 1] = baralho[b - 1] = baralho[c - 1] = baralho[x - 1] = baralho[y - 1] = true;

        vector<int> Princesa = {a, b, c};
        sort(Princesa.begin(), Princesa.end());

        int z = -1;
        for (int i = 0; i < 52; i++) {
            if (!baralho[i]) {
                vector<int> Principe = {x, y, i + 1};
                sort(Principe.begin(), Principe.end());

                int win = 0;
                if (Principe[2] > Princesa[0]) win++;
                if (Principe[1] > Princesa[2]) win++;
                if (Principe[0] > Princesa[1]) win++;

                if (win >= 2) {
                    z = i + 1;
                    break;
                }
            }
        }

        cout << z << endl;
    }

    return 0;
}
