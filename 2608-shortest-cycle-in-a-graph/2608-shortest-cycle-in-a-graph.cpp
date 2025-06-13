class Solution {
public:
    int dfs(int start, vector<vector<int>>&adj, int tar, vector<int>&vis, int par){
        vis[start]=1;
        int len=1e9;
        for(auto it:adj[start]){
            if(it==par)continue;
            if(!vis[it]){
                int cal=dfs(it,adj,tar,vis,start);
                if(cal>0)len=min(len,cal+1);
            }
            else if(it==tar && vis[it]) return 1;
        }
        vis[start]=0;
        if(len==1e9)return 0;
        return len;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int len=1e9;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            int par=-1;
           int ans= dfs(i,adj,i,vis,par);
            if(ans!=0)len=min(len,ans);
        }
        if(len==1e9)return -1;
        return len;
        
    }
};