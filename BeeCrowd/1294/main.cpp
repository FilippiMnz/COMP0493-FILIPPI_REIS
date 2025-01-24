#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

double calcular_volume(double L, double W, double x) {
    return (L - 2 * x) * (W - 2 * x) * x;
}

int main() {
    double L, W;

    cout << fixed << setprecision(3);

    while (cin >> L >> W) {
        double x_max = (4 * L + 4 * W - sqrt((4 * L + 4 * W) * (4 * L + 4 * W) - 48 * L * W)) / 24;
        double x_min1 = 0.0;
        double x_min2 = min(L, W) / 2.0;

        cout << x_max << " " << x_min1 << " " << x_min2 << endl;
    }

    return 0;
}

