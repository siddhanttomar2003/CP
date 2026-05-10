class Solution {
public:
    typedef long long ll;
    vector<vector<vector<int>>>adj;
    void bfs1(int s, vector<ll>&dis1){
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
        q.push({0, s});
        while(q.size() > 0){
            auto it = q.top();
            q.pop();
            int u = it.second;
            ll c = it.first;
            if(c > dis1[u])continue;
            for(auto& it2 : adj[u]){
                ll v = it2[0], w = it2[1];
                if(dis1[v] > c + w){
                    dis1[v] = c + w;
                    q.push({dis1[v], v});
                }
            }
        }
    }
    void bfs2(int s, vector<ll>&dis2){
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
        q.push({0, s});
        while(q.size() > 0){
            auto it = q.top();
            q.pop();
            int u = it.second;
            ll c = it.first;
            if(c > dis2[u])continue;
            for(auto& it2 : adj[u]){
                ll v = it2[0], w = it2[1], m = it2[2];
                if(dis2[v] > c + w * m){
                    dis2[v] = c + w * m;
                    q.push({dis2[v], v});
                }
            }
        }
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        adj.resize(n);
        for(auto& it : roads){
            int u = it[0], v = it[1], c = it[2], t = it[3];
            adj[u].push_back({v, c, t});
            adj[v].push_back({u, c, t});
        }
        vector<int>ans(n);
        // without carrying
        for(int i = 0; i < n; i++){
            vector<ll>nc(n, 1e18), c(n, 1e18);
            bfs1(i, c);
            bfs2(i, nc);
            ll mini = prices[i];
            for(int j = 0; j < n; j++){
                if(i != j)mini = min(mini, prices[j] + nc[j] + c[j]);
            }
            ans[i] = mini;
        }
        return ans;
    }
};