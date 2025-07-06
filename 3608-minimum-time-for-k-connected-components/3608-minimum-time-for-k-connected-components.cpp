class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    void dfs(int start, vector<int>&vis, int t){
        vis[start] = 1;
        for(auto it : adj[start]){
            if(!vis[it.first] && it.second > t){
                dfs(it.first, vis, t);
            }
        }
    }
    bool check(int curr_time, int k, int n){
      
      int comp = 0;
      vector<int>vis(n, 0);
      for(int i = 0; i < n; i++){
        if(!vis[i]){
            comp++;
            dfs(i, vis, curr_time);
        }
      }
      return comp >= k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int maxi = 0;
        // vector<vector<pair<int,int>>>adj(n);
        adj.resize(n);
        for(auto it : edges){
            maxi = max(maxi , it[2]);
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int low = 0;
        int high = maxi;
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, k, n)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};