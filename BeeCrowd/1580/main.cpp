#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

ll fast_exponentiation(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll fat(int n) {
    ll res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    string s;
    while (getline(cin, s) && !s.empty()) {
        ll f = fat(s.size());
        map<char, int> freq;
        
        for (char c : s) {
            freq[c]++;
        }
        
        ll x = 1;
        for (auto& p : freq) {
            x = (x * fat(p.second)) % MOD;
        }
        
        ll result = (f * fast_exponentiation(x, MOD - 2, MOD)) % MOD;
        cout << result << endl;
    }
    return 0;
}
