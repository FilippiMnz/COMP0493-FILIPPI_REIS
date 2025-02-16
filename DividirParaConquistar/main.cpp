#include <bits/stdc++.h>
using namespace std;


long long binExp(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp) {
        if (exp % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int inversionCount(vector<int>& arr) {
    int count = 0;
    function<void(int, int)> mergeSortCount = [&](int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSortCount(l, m);
        mergeSortCount(m + 1, r);
        int i = l, j = m + 1, k = 0;
        vector<int> temp(r - l + 1);
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else { temp[k++] = arr[j++]; count += (m - i + 1); }
        }
        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        copy(temp.begin(), temp.end(), arr.begin() + l);
    };
    mergeSortCount(0, arr.size() - 1);
    return count;
}

vector<int> computeLCP(const string& s, const vector<int>& suffixArray) {
    int n = s.size(), h = 0;
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; i++) rank[suffixArray[i]] = i;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = suffixArray[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}