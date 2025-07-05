#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        
        // 1. Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        vector<bool> removed(n, false);
        queue<int> q;
        
        // 2. Initial prune: remove all leaves that have no coin
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i] == 0) {
                removed[i] = true;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (removed[v]) continue;
                if (--deg[v] == 1 && coins[v] == 0) {
                    removed[v] = true;
                    q.push(v);
                }
            }
        }
        
        // 3. Prune two more “layers” of leaves (regardless of coins)
        for (int round = 0; round < 2; round++) {
            vector<int> leaves;
            for (int i = 0; i < n; i++) {
                if (!removed[i] && deg[i] == 1) {
                    leaves.push_back(i);
                }
            }
            for (int u : leaves) {
                removed[u] = true;
                for (int v : adj[u]) {
                    if (!removed[v]) {
                        deg[v]--;
                    }
                }
            }
        }
        
        // 4. Count remaining edges in the “core”
        int remainEdges = 0;
        for (auto &e : edges) {
            if (!removed[e[0]] && !removed[e[1]])
                remainEdges++;
        }
        
        // Each edge must be traversed twice (out + back)
        return remainEdges * 2;
    }
};
