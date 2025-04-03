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


class FordFulkerson {
private:
    vector<vector<int>> capacity;
    vector<vector<int>> adj;
    int n;

    int dfs(int s, int t, int min_capacity, vector<bool>& visited) {
        if (s == t) return min_capacity;
        visited[s] = true;
        
        for (int v : adj[s]) {
            if (!visited[v] && capacity[s][v] > 0) {
                int flow = dfs(v, t, min(min_capacity, capacity[s][v]), visited);
                if (flow > 0) {
                    capacity[s][v] -= flow;
                    capacity[v][s] += flow;
                    return flow;
                }
            }
        }
        return 0;
    }

public:
    FordFulkerson(int num_nodes) : n(num_nodes) {
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
        vector<bool> visited(n);
        
        while (true) {
            fill(visited.begin(), visited.end(), false);
            int flow = dfs(s, t, INT_MAX, visited);
            if (flow == 0) break;
            max_flow += flow;
        }
        
        return max_flow;
    }
};