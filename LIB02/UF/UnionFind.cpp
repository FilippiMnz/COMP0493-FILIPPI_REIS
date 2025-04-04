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


vector<pair<int, pair<int, int>>> kruskal_mst(vector<pair<int, pair<int, int>>>& edges, int n) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    vector<pair<int, pair<int, int>>> mst;
    
    for (auto& edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (uf.find(u) != uf.find(v)) {
            mst.push_back(edge);
            uf.union_sets(u, v);
            if (mst.size() == n - 1) break;
        }
    }
    
    return mst;
}

vector<vector<pair<int, int>>> prim_mst(const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<bool> in_mst(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    key[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        in_mst[u] = true;
        
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (!in_mst[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    vector<vector<pair<int, int>>> mst(n);
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            mst[parent[i]].push_back({i, key[i]});
        }
    }
    
    return mst;
}