class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<vector<int>>dis(n, vector<int>(k + 1, 2e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0, 0, src});
        dis[src][0] = 0;
        while(pq.size() > 0){
            auto it = pq.top();
            int c = it[0];
            int stops = it[1];
            int node = it[2];
            pq.pop();
            for(auto it2 : adj[node]){
                int child = it2.first;
                int curr = it2.second;
                if(dis[child][stops] > c + curr){
                    dis[child][stops] = c + curr;
                    if(stops + 1 <= k)
                    pq.push({c + curr, stops + 1, child});
                }
            }
        }
        int ans = 2e9;
        for(auto it : dis[dst]){
            ans = min(ans, it);
        }
        if(ans == 2e9)return -1;
        return ans;
    }
};