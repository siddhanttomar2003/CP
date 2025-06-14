class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>>dis(n,vector<int>(k+1,1e9));
        dis[src][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,src});
        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            int curr_cost=it[0];
            int stops=it[1];
            int par=it[2];
            for(auto item:adj[par]){
                int child=item.first;
                int wt=item.second;
                if(dis[child][stops]>wt+curr_cost && stops<=k){
                    dis[child][stops]=wt+curr_cost;
                    if(stops+1<=k){
                    pq.push({dis[child][stops],stops+1,child});
                    }
                }
            }
        }
        int mini=1e9;
        for(int i=0;i<=k;i++){
            mini=min(mini,dis[dst][i]);
        }
        if(mini==1e9)return -1;
        return mini;
    }
};