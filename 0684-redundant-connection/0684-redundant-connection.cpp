class Solution {
public:
    void dfs(unordered_map<int,unordered_set<int>>&mp, int start, vector<int>&vis){
        vis[start]=1;
        for(auto it:mp[start]){
            if(!vis[it]){
                dfs(mp,it,vis);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,unordered_set<int>>mp;
        for(auto it:edges){
            mp[it[0]].insert(it[1]);
            mp[it[1]].insert(it[0]);
        }
        for(int i=n-1;i>=0;i--){
            vector<int>vis(n+1,0);
            int u=edges[i][0],v=edges[i][1];
            mp[u].erase(v);
            mp[v].erase(u);
            dfs(mp,1,vis);
            bool check=true;
            for(int i=1;i<=n;i++){
                if(!vis[i])check=false;
            }
            if(check)return {u,v};
            mp[u].insert(v);
            mp[v].insert(u);
        }
        return {-1,-1};
    }
};