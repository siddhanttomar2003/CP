class Solution {
public:
    void dfs(int start, vector<int>&vis, vector<vector<pair<int,int>>>&adj, int mw){
        vis[start]=1;
        for(int i=0;i<adj[start].size();i++){
            int child=adj[start][i].second;
            int w=adj[start][i].first;
            if(w>mw)break;
            if(!vis[child]){
                dfs(child,vis,adj,mw);
            }
        }
    }
    bool check(int max_w, vector<vector<pair<int,int>>>&adj, int n){
        vector<int>vis(n,0);
        dfs(0,vis,adj,max_w);
        for(int i=1;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        int maxi=1;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            maxi=max(maxi,w);
            adj[v].push_back({w,u});
        }
        for(int i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end());
        }
        int low=1;
        int high=maxi;
        int ans=-1;
        while(low<=high){
           int m=low+(high-low)/2;
           if(check(m,adj,n)){
            ans=m;
            high=m-1;
           }
           else low=m+1;
        }
        return ans;

    }
};