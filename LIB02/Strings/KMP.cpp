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

vector<int> kmp_preprocess(const string& pattern) {
    vector<int> lps(pattern.size(), 0);
    int len = 0;
    int i = 1;
    
    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp_search(const string& text, const string& pattern) {
    vector<int> lps = kmp_preprocess(pattern);
    vector<int> matches;
    int i = 0; 
    int j = 0; 
    
    while (i < text.size()) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == pattern.size()) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}
