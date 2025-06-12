class Solution {
public:
    bool dfs(vector<int>&vis1,vector<int>&vis2,vector<vector<int>>&adj,int start){
        vis1[start]=1;
        vis2[start]=1;
        bool c=false;
        for(auto it:adj[start]){
            if(!vis1[it] && !vis2[it]){
                c|=dfs(vis1,vis2,adj,it);
            }
            else if(vis2[it]){
                return true;
            }
        }
        vis2[start]=0;
        return c;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(auto it:p){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis1(n,0);
        bool check=false;
        for(int i=0;i<n;i++){
            if(!vis1[i]){
            vector<int>vis2(n,0);
            check|=dfs(vis1,vis2,adj,i);
            }
            if(check)return false;
        }
        return true;
    }
};