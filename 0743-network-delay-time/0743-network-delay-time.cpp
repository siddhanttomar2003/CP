class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dis(n+1,1e9);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dis[k]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,k});
        while(pq.size()>0){
            auto it=pq.top();
            int curr_dis=it[0];
            int par=it[1];
            pq.pop();
            for(auto it:adj[par]){
                int child=it.first;
                int wt=it.second;
                if(dis[child]>wt+curr_dis){
                    dis[child]=wt+curr_dis;
                    pq.push({dis[child],child});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dis[i]);
        }
        if(ans==1e9)return -1;
        return ans;
    }
};