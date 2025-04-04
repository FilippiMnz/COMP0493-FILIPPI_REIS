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

vector<int> boyer_moore_search(const string& text, const string& pattern) {
    vector<int> matches;
    int n = text.size();
    int m = pattern.size();
    
    if (m == 0 || n < m) return matches;
    
    vector<int> bad_char(256, -1);
    for (int i = 0; i < m; i++) {
        bad_char[(int)pattern[i]] = i;
    }
    
    int s = 0; 
    while (s <= (n - m)) {
        int j = m - 1;
        
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        
        if (j < 0) {
            matches.push_back(s);
            s += (s + m < n) ? m - bad_char[text[s + m]] : 1;
        } else {
            s += max(1, j - bad_char[text[s + j]]);
        }
    }
    
    return matches;
}