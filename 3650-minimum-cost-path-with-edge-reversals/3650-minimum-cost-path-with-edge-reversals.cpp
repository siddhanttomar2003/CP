class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2 * it[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0});
        vector<int>dis(n, 1e9);
        dis[0] = 0;
        while(pq.size() > 0){
            int curr_dis = pq.top()[0];
            int par = pq.top()[1];
            pq.pop();
            for(auto it : adj[par]){
                int child = it.first;
                int f_dis = it.second;
                if(dis[child] > curr_dis + f_dis){
                    dis[child] = curr_dis + f_dis;
                    pq.push({dis[child], child});
                }
            }
        }
        if(dis[n - 1] == 1e9)return -1;
        return dis[n - 1];
    }
};