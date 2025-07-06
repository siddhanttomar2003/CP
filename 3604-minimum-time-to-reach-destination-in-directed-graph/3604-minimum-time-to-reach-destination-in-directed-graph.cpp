typedef long long ll;
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n == 1)return 0;
        int state = 0; 
        int end = n - 1;
        vector<vector<vector<int>>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2], it[3]});
        }
        vector<ll>dis(n, 1e12);
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
        pq.push({0,0});
        while(pq.size() > 0){
            auto it = pq.top();
            pq.pop();
            int par = it[1];
            ll curr_time = it[0];
            for(auto& it2 : adj[par]){
                ll child = it2[0];
                ll s= it2[1], e= it2[2];
                if(curr_time > e)continue;
                ll maxi = max(curr_time, s);
                if(dis[child] > 1 + maxi){
                    dis[child] = 1 + maxi;
                    pq.push({dis[child], child});
                }
            }
        }
        if(dis[n - 1] ==  1e12)return -1;
        return dis[n - 1];
    }
};