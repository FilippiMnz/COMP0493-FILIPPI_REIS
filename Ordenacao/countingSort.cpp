#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for (int x : arr) count[x]++;
    arr.clear();
    for (int i = 0; i <= maxVal; i++) while (count[i]--) arr.push_back(i);
}

