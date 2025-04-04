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

class FenwickTree {
    private:
        vector<int> tree;
        int n;
    
    public:
        FenwickTree(int size) : n(size) {
            tree.assign(n + 1, 0);
        }
    
        void build(const vector<int>& arr) {
            for (int i = 0; i < n; i++) {
                update(i + 1, arr[i]);
            }
        }
    
        void update(int idx, int delta) {
            while (idx <= n) {
                tree[idx] += delta;
                idx += idx & -idx;
            }
        }
    
        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += tree[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    
        int range_query(int l, int r) {
            return query(r) - query(l - 1);
        }
    };
    