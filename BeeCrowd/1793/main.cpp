#include <iostream>
#include <iomanip>
using namespace std;

struct Ponto {
    double x, y;
};


Ponto calcularBuracoNegro(Ponto antiga1, Ponto nova1, Ponto antiga2, Ponto nova2) {
    
    double A1 = nova1.x - antiga1.x;
    double B1 = nova1.y - antiga1.y;
    double C1 = (antiga1.x + nova1.x) / 2 * A1 + (antiga1.y + nova1.y) / 2 * B1;

    double A2 = nova2.x - antiga2.x;
    double B2 = nova2.y - antiga2.y;
    double C2 = (antiga2.x + nova2.x) / 2 * A2 + (antiga2.y + nova2.y) / 2 * B2;


    double det = A1 * B2 - A2 * B1;
    double x = (C1 * B2 - C2 * B1) / det;
    double y = (A1 * C2 - A2 * C1) / det;

    return {x, y};
}

int main() {
    int T;
    cin >> T;
    cout << fixed << setprecision(2);

    for (int caso = 1; caso <= T; ++caso) {
        Ponto antiga1, nova1, antiga2, nova2;
        cin >> antiga1.x >> antiga1.y >> antiga2.x >> antiga2.y;
        cin >> nova1.x >> nova1.y >> nova2.x >> nova2.y;

        Ponto buracoNegro = calcularBuracoNegro(antiga1, nova1, antiga2, nova2);
        cout << "Caso #" << caso << ": " << buracoNegro.x << " " << buracoNegro.y << endl;
    }

    return 0;
}

