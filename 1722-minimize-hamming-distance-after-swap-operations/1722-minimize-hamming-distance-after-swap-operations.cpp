class Solution {
public:
    void dfs(vector<int>&c, vector<int>&vis, int node, vector<vector<int>>&adj){
        vis[node] = 1;
        c.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(c, vis, it, adj);
            }
        }
    }
    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& a) {
        int n = s.size();
        vector<vector<int>>adj(n);
        for(auto it : a){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;
        vector<int>vis(n, 0);
        for(int i = 0; i < n; i++){
            vector<int>cycle;
            if(!vis[i]){
                dfs(cycle, vis, i, adj);
            }
            map<int, int>freq;
            for(auto it : cycle){
                freq[t[it]]++;
                freq[s[it]]--;
            }
            for(auto it : freq){
                if(it.second > 0)count += it.second;
            }
        }
        return count;
    }
};