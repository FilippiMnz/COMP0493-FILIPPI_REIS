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

class Dinic {
    private:
        struct Edge {
            int v, rev, cap, flow;
            Edge(int _v, int _rev, int _cap) : v(_v), rev(_rev), cap(_cap), flow(0) {}
        };
    
        vector<vector<Edge>> adj;
        vector<int> level;
        vector<int> ptr;
        int n;
    
        bool bfs(int s, int t) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            queue<int> q;
            q.push(s);
    
            while (!q.empty()) {
                int u = q.front();
                q.pop();
    
                for (Edge& e : adj[u]) {
                    if (level[e.v] == -1 && e.cap - e.flow > 0) {
                        level[e.v] = level[u] + 1;
                        q.push(e.v);
                    }
                }
            }
            return level[t] != -1;
        }
    
        int dfs(int u, int t, int flow) {
            if (u == t || flow == 0) return flow;
    
            for (int& i = ptr[u]; i < adj[u].size(); i++) {
                Edge& e = adj[u][i];
                if (level[e.v] == level[u] + 1 && e.cap - e.flow > 0) {
                    int pushed = dfs(e.v, t, min(flow, e.cap - e.flow));
                    if (pushed > 0) {
                        e.flow += pushed;
                        adj[e.v][e.rev].flow -= pushed;
                        return pushed;
                    }
                }
            }
            return 0;
        }
    
    public:
        Dinic(int num_nodes) : n(num_nodes) {
            adj.resize(n);
            level.resize(n);
            ptr.resize(n);
        }
    
        void add_edge(int u, int v, int cap) {
            Edge forward(v, adj[v].size(), cap);
            Edge backward(u, adj[u].size(), 0);
            adj[u].push_back(forward);
            adj[v].push_back(backward);
        }
    
        int max_flow(int s, int t) {
            int max_flow = 0;
            
            while (bfs(s, t)) {
                fill(ptr.begin(), ptr.end(), 0);
                while (int pushed = dfs(s, t, INT_MAX)) {
                    max_flow += pushed;
                }
            }
            
            return max_flow;
        }
    };
    