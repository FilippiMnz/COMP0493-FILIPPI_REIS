#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<double>& arr) {
    int n = arr.size();
    vector<vector<double>> buckets(n);
    for (double x : arr) buckets[x * n].push_back(x);
    for (auto &b : buckets) sort(b.begin(), b.end());
    arr.clear();
    for (auto &b : buckets) for (double x : b) arr.push_back(x);
}
