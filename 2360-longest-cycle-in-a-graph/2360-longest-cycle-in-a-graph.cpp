class Solution {
public:
    pair<int,bool> dfs(int &len, vector<vector<int>>&adj,int start,vector<int>&vis, int &c_s){
        vis[start]=1;
        bool check=false;
        int cycle_len=0;
        for(auto it:adj[start]){
            if(!vis[it]){
                pair<int,bool> temp=dfs(len,adj,it,vis,c_s);
                if(temp.second && start==c_s)len=max(len,temp.first+1);
                cycle_len=temp.first;
                check=temp.second;
            }
            else {
                c_s=it;
                return {1,true};
            }
        }
        if(start==c_s){
            c_s=-1;
            return {0,false};
        }
        if(check)return {1+cycle_len,true};
        return {0,false};
    }
    int longestCycle(vector<int>& edges) {
        int len=-1;
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)adj[i].push_back(edges[i]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int c_s=-1;
                dfs(len,adj,i,vis,c_s);
            }
        }
        return len;
    }
};