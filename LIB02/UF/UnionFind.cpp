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

class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
        int num_sets;
    
    public:
        UnionFind(int n) : num_sets(n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
    
        int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]); 
            }
            return parent[u];
        }
    
        void union_sets(int u, int v) {
            int root_u = find(u);
            int root_v = find(v);
            
            if (root_u != root_v) {
                if (rank[root_u] > rank[root_v]) {
                    parent[root_v] = root_u;
                } else if (rank[root_u] < rank[root_v]) {
                    parent[root_u] = root_v;
                } else {
                    parent[root_v] = root_u;
                    rank[root_u]++;
                }
                num_sets--;
            }
        }
    
        int get_num_sets() const {
            return num_sets;
        }
    };