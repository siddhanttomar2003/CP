typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
const int m=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>paths(n,0);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<ll>dis(n,1e12);
        priority_queue<vl,vvl,greater<vl>>pq;
        pq.push({0,0});
        paths[0]=1;
        dis[0]=0;
        while(pq.size()>0){
            ll curr_dis=pq.top()[0];
            ll par=pq.top()[1];
            pq.pop();
            for(auto it:adj[par]){
                int child=it.first;
                ll wt=it.second;
                if(dis[child]>wt+curr_dis){
                    dis[child]=wt+curr_dis;
                    paths[child]=paths[par];
                    pq.push({dis[child],child});
                }
                else if(dis[child]==wt+curr_dis){
                  paths[child]=(paths[child]+paths[par])%m;
                }
            }
        }
        return paths[n-1];
     
    }
};