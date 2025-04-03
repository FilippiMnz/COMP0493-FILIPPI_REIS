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

class EdmondsKarp {
    private:
        vector<vector<int>> capacity;
        vector<vector<int>> adj;
        int n;
    
        int bfs(int s, int t, vector<int>& parent) {
            fill(parent.begin(), parent.end(), -1);
            parent[s] = -2;
            queue<pair<int, int>> q;
            q.push({s, INT_MAX});
    
            while (!q.empty()) {
                int u = q.front().first;
                int flow = q.front().second;
                q.pop();
    
                for (int v : adj[u]) {
                    if (parent[v] == -1 && capacity[u][v] > 0) {
                        parent[v] = u;
                        int new_flow = min(flow, capacity[u][v]);
                        if (v == t) return new_flow;
                        q.push({v, new_flow});
                    }
                }
            }
            return 0;
        }
    
    public:
        EdmondsKarp(int num_nodes) : n(num_nodes) {
            capacity.assign(n, vector<int>(n, 0));
            adj.resize(n);
        }
    
        void add_edge(int u, int v, int cap) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v] = cap;
        }
    
        int max_flow(int s, int t) {
            int max_flow = 0;
            vector<int> parent(n);
            
            while (true) {
                int flow = bfs(s, t, parent);
                if (flow == 0) break;
                
                max_flow += flow;
                int v = t;
                while (v != s) {
                    int u = parent[v];
                    capacity[u][v] -= flow;
                    capacity[v][u] += flow;
                    v = u;
                }
            }
            
            return max_flow;
        }
    };