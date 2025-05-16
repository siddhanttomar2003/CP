class Solution {
public:
    // unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
    vector<vector<unordered_map<int, int>>>dp ;

    int memoI(vector<pair<int,int>> adj[], int node, int k, int t, int orik) {
        if (t <= 0) return -1e9 ;
        if (k == 0) return 0 ;
        
        if (dp[node][k][t]) return dp[node][k][t] ;

        int ans = -1e9 ;
        if (k == orik) 
        {
            for(auto [nn, nnw] : adj[node]) ans = max(ans, memoI(adj, nn, k, t, orik)) ;
            for(auto [nn, nnw] : adj[node]) ans = max(ans, nnw + memoI(adj, nn, k - 1, t - nnw, orik)) ;
        } 
        else 
        {
            for(auto [nn, nnw] : adj[node]) ans = max(ans, nnw + memoI(adj, nn, k - 1, t - nnw, orik)) ;
        }

        return dp[node][k][t] = ans;
    }

    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        dp.resize(n, vector<unordered_map<int, int>>(k+1)) ;

        vector<pair<int,int>> adj[n];
        vector<int> indeg(n, 0);

        for (auto& edge : edges) {
            indeg[edge[1]]++;
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }

        int mxSum = -1;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                mxSum = max(mxSum, memoI(adj, i, k, t, k));
            }
        }

        return mxSum;
    }
};