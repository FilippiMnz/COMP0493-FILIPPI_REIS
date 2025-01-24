#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int instancia = 1;

    while (true) {
        
        int n, k;
        cin >> n >> k;

        if (n == 0 && k == 0) {
            break;
        }

        
        vector<string> nomes(n);
        for (int i = 0; i < n; ++i) {
            cin >> nomes[i];
        }

        
        for (int j = 0; j < nomes.size(); ++j) {
            
            int limite = min(j + k + 1, (int)nomes.size());
            int menorIndice = j;

            for (int l = j + 1; l < limite; ++l) {
                if (nomes[l] < nomes[menorIndice]) {
                    menorIndice = l;
                }
            }

          
            while (menorIndice > j && k > 0) {
                swap(nomes[menorIndice], nomes[menorIndice - 1]);
                --menorIndice;
                --k;
            }
        }

        
        cout << "Instancia " << instancia << endl;
        for (const auto &nome : nomes) {
            cout << nome << " ";
        }
        cout << endl << endl;

        ++instancia;
    }

    return 0;
}

