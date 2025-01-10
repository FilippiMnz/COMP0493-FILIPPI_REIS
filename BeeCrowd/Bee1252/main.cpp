#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m, n || m) {
        cout << n << " " << m << "\n";

        vector<long long> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        sort(numbers.begin(), numbers.end(), [m](long long a, long long b) {
            if (a % m != b % m) {
                return a % m < b % m;
            }
            if ((a % 2 != 0) != (b % 2 != 0)) {
                return a % 2 != 0;
            }
            if (a % 2 != 0) {
                return a > b;
            }
            return a < b;
        });

        for (const auto& num : numbers) {
            cout << num << "\n";
        }
    }

    cout << "0 0\n";
    return 0;
}

