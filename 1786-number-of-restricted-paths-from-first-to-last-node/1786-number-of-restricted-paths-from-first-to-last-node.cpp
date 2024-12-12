const int M = 1e9 + 7;
typedef long long ll;
class Solution {
public:
    int dfs(int start, vector<int>& paths, vector<ll>& last_dis,
            vector<vector<pair<int, ll>>>& adj) {
        if (start == paths.size() - 1) {
            return paths[start]=1;
        }
        if (paths[start] != -1)
            return paths[start];
        int ans = 0;
        for (int i = 0; i < adj[start].size(); i++) {
            int child = adj[start][i].first;
            if (last_dis[start] > last_dis[child]) {
                ans = (ans + dfs(child, paths, last_dis, adj)) % M;
            }
        }
        return paths[start] = ans % M;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, ll>>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            ll wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<ll> last_dis(n + 1, 1e18);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            pq;
        pq.push({0, n});
        last_dis[n] = 0;
        while (pq.size() > 0) {
            int par = pq.top().second;
            int curr_dis = pq.top().first;
            pq.pop();
            for (int i = 0; i < adj[par].size(); i++) {
                int child = adj[par][i].first;
                int wt = adj[par][i].second;
                if (last_dis[child] > curr_dis + wt) {
                    last_dis[child] = curr_dis + wt;
                    pq.push({last_dis[child], child});
                }
            }
        }
        vector<int> paths(n + 1, -1);
        return dfs(1, paths, last_dis, adj);
    }
};