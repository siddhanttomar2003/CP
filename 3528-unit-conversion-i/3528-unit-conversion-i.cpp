typedef long long ll;
class Solution {
public:
    const int m =1e9+7;
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n=conversions.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:conversions){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<vector<int>>q;
        q.push({0,1});
        vector<int>vis(n+1,0),ans(n+1,0);
        vis[0]=1;
        ans[0]=1;
        while(q.size()>0){
         int par=q.front()[0];
         int curr=q.front()[1];
         q.pop();
         for(auto it:adj[par]){
            int child=it.first;
            int w=it.second;
            if(!vis[child]){
              vis[child]=1;
              ans[child]=(w*1ll*curr)%m;
              q.push({child,ans[child]});
            }
         }
        }
        return ans;

    }
};