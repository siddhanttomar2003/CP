
class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& vis, int par,
             int start, vector<int>& par_child) {
        par_child[start] = par;
        vis[start] = 1;
        for (int i = 0; i < adj[start].size(); i++) {
            int child = adj[start][i].first;
            if (!vis[child]) {
                dfs(adj, vis, par, child, par_child);
            }
        }
    }
    void dfs2(vector<vector<pair<int, int>>>& adj, set<vector<int>>& st, int& bita,
              int start) {
        for (int i = 0; i < adj[start].size(); i++) {
            int child = adj[start][i].first;
            int wt = adj[start][i].second;
            int u=min(start,child);
            int v=max(start,child);
            if (st.find({u,v,wt})==st.end()) {
                bita &= wt;
                st.insert({u,v,wt});
                dfs2(adj, st, bita, child);
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> par_child(n);
        for(int i=0;i<n;i++)par_child[i]=i;
        vector<int> par_and(n,-1);
        vector<int> vis(n, 0);
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, vis, i, i, par_child);
                if (adj[i].size() >= 1) {
                    int bita = adj[i][0].second;
                    dfs2(adj, st, bita, i);
                    par_and[i] = bita;
                }
            }
        }
        vector<int> ans;
        for (auto &it : query) {
            int u = it[0], v = it[1];
                if (par_child[u] == par_child[v])
                    ans.push_back(par_and[par_child[u]]);
                else
                    ans.push_back(-1);
        }
        return ans;
    }
};