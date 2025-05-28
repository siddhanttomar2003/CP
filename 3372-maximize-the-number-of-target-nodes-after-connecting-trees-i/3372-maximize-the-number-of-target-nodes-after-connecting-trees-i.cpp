class Solution {
public:
    int bfs(int start, vector<vector<int>>&adj,int n,int k){
         if(k<0)return 0;
         vector<int>vis(n,0);
         queue<vector<int>>q;
         q.push({0,start});
         int count=0;
         vis[start]=1;
         while(!q.empty()){
            int par=q.front()[1];
            int curr_dis=q.front()[0];
            q.pop();
            count++;
            for(auto it:adj[par]){
                if(!vis[it] && curr_dis+1<=k){
                      vis[it]=1;
                      q.push({curr_dis+1,it});
                }
            }
         }
         return count;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
         int n=edges1.size();
         int m=edges2.size();
         vector<vector<int>>adj1(n+1),adj2(m+1);
         for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
         }
         for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
         }
         int maxi=0;
         for(int i=0;i<=m;i++){
            maxi=max(maxi,bfs(i,adj2,m+1,k-1));
         }
         vector<int>ans(n+1);
         for(int i=0;i<=n;i++){
            ans[i]=bfs(i,adj1,n+1,k)+maxi;
         }
         return ans;
    }
};