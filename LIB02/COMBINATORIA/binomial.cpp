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

long long binomial_coefficient_analytical(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;
    
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res *= (n - k + i);
        res /= i;
    }
    return res;
}

long long binomial_coefficient_recursive(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomial_coefficient_recursive(n - 1, k - 1) + 
           binomial_coefficient_recursive(n - 1, k);
}