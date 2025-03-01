#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool eh_primo(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool eh_super_primo(int n) {
    string num = to_string(n);
    vector<int> digitos_primos = {2, 3, 5, 7};
    for (char c : num) {
        if (find(digitos_primos.begin(), digitos_primos.end(), c - '0') == digitos_primos.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        if (!eh_primo(n)) {
            cout << "Nada" << endl;
        } else if (eh_super_primo(n)) {
            cout << "Super" << endl;
        } else {
            cout << "Primo" << endl;
        }
    }
    return 0;
}
