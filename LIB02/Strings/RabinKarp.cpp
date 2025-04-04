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

vector<int> rabin_karp_search(const string& text, const string& pattern, int prime = 101) {
    vector<int> matches;
    int n = text.size();
    int m = pattern.size();
    int d = 256; 
    
    if (n < m) return matches;
    
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % prime;
    }
    
    int pattern_hash = 0;
    int text_hash = 0;
    for (int i = 0; i < m; i++) {
        pattern_hash = (d * pattern_hash + pattern[i]) % prime;
        text_hash = (d * text_hash + text[i]) % prime;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                matches.push_back(i);
            }
        }
        
        if (i < n - m) {
            text_hash = (d * (text_hash - text[i] * h) + text[i + m]) % prime;
            if (text_hash < 0) {
                text_hash += prime;
            }
        }
    }
    
    return matches;
}
