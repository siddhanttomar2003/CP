class Solution {
public:
    int dijkstra(int n,int start, vector<vector<int>>&adj){
         vector<int>dis(n,1000);
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         pq.push({0,0});
         dis[0]=0;
         while(pq.size()>0){
            int wt=pq.top().first;
            int par=pq.top().second;
            pq.pop();
            for(int i=0;i<adj[par].size();i++){
                int child=adj[par][i];
                if(dis[child]>dis[par]+1){
                    dis[child]=dis[par]+1;
                    pq.push({dis[child],child});
                }
            }
         }
         return dis[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            adj[u].push_back(v);
            int dis= dijkstra(n,0,adj);
            ans.push_back(dis);
        }
        return ans;
    }
};