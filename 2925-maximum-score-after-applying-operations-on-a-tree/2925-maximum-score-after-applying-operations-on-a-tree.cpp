typedef long long ll;
class Solution {
public:
    ll dfs(vector<vector<int>>&adj,int node, vector<int>&values, vector<int>&vis){
         vis[node]=1;
         ll curr=values[node];
         ll mini=1e9;
         ll sum=0;
         for(auto it:adj[node]){
            if(!vis[it]){
                 sum+=(dfs(adj,it,values,vis));
            }
         }
         if(sum>0)mini=sum;
         return min(mini,curr);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        ll sum=0;
        sum=accumulate(values.begin(),values.end(),0*1ll);
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        ll mini_sum=dfs(adj,0,values,vis);
        return sum-mini_sum;
    }
};