#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

bool is_prime_brute_force(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_prime_miller_rabin(int n, int k = 5) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    int s = 0;
    int d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 3);
        int x = 1;
        for (int j = 0; j < d; j++) {
            x = (1LL * x * a) % n;
        }
        if (x == 1 || x == n - 1) continue;

        bool composite = true;
        for (int j = 0; j < s - 1; j++) {
            x = (1LL * x * x) % n;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}