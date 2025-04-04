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

class SegmentTree {
    private:
        vector<int> tree;
        vector<int> lazy;
        int n;
        int operation; 
    
        void build(const vector<int>& arr, int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
            } else {
                int mid = (start + end) / 2;
                build(arr, 2 * node, start, mid);
                build(arr, 2 * node + 1, mid + 1, end);
                
                if (operation == 0) tree[node] = tree[2 * node] + tree[2 * node + 1];
                else if (operation == 1) tree[node] = min(tree[2 * node], tree[2 * node + 1]);
                else tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            }
        }
    
        void push(int node, int start, int end) {
            if (lazy[node] != 0) {
                if (operation == 0) {
                    tree[node] += (end - start + 1) * lazy[node];
                } else {
                    tree[node] += lazy[node];
                }
                
                if (start != end) {
                    lazy[2 * node] += lazy[node];
                    lazy[2 * node + 1] += lazy[node];
                }
                lazy[node] = 0;
            }
        }
    
        void update_range(int node, int start, int end, int l, int r, int val) {
            push(node, start, end);
            if (start > r || end < l) return;
            
            if (l <= start && end <= r) {
                lazy[node] += val;
                push(node, start, end);
                return;
            }
            
            int mid = (start + end) / 2;
            update_range(2 * node, start, mid, l, r, val);
            update_range(2 * node + 1, mid + 1, end, l, r, val);
            
            if (operation == 0) tree[node] = tree[2 * node] + tree[2 * node + 1];
            else if (operation == 1) tree[node] = min(tree[2 * node], tree[2 * node + 1]);
            else tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    
        int query_range(int node, int start, int end, int l, int r) {
            push(node, start, end);
            if (start > r || end < l) {
                if (operation == 0) return 0;
                else if (operation == 1) return INT_MAX;
                else return INT_MIN;
            }
            
            if (l <= start && end <= r) return tree[node];
            
            int mid = (start + end) / 2;
            int left = query_range(2 * node, start, mid, l, r);
            int right = query_range(2 * node + 1, mid + 1, end, l, r);
            
            if (operation == 0) return left + right;
            else if (operation == 1) return min(left, right);
            else return max(left, right);
        }
    
    public:
        SegmentTree(const vector<int>& arr, int op) : operation(op) {
            n = arr.size();
            tree.resize(4 * n);
            lazy.assign(4 * n, 0);
            build(arr, 1, 0, n - 1);
        }
    
        void update(int idx, int val) {
            update_range(1, 0, n - 1, idx, idx, val);
        }
    
        void update_range(int l, int r, int val) {
            update_range(1, 0, n - 1, l, r, val);
        }
    
        int query(int l, int r) {
            return query_range(1, 0, n - 1, l, r);
        }
    };