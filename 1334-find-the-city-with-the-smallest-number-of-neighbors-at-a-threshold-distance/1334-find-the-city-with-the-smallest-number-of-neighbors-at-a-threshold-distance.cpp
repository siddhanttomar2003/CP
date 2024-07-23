class Solution {
public:
    void dijkstra(int start, int threshold, vector<vector<pair<int,int>>> &adj,map<int,int> &mp,int n){
          vector<int> dis(n,1e9);
          dis[start]=0;
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          pq.push({0,start});
          while(pq.size()>0){
            int num=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(int i=0;i<adj[num].size();i++){
                int nd=adj[num][i].second;
                int child=adj[num][i].first;
                if(dis[child]>dis[num]+nd && dis[num]+nd<=threshold){
                    dis[child]=dis[num]+nd;
                    pq.push({dis[child],child});
                }
            }
          }
          int count=0;
          for(int i=0;i<n;i++){
            if(i!=start){
                if(dis[i]!=1e9)count++;
            }
          }
          mp[start]=count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // first apply dijkstra for every city;
        map<int,int> mp;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        for(int i=0;i<n;i++){
            dijkstra(i,distanceThreshold,adj,mp,n);
        }
        int ansi=0;
        int maxi=n;
        for(auto it:mp){
            if(it.second<=maxi){
                maxi=it.second;
                ansi=it.first;
            }
        }
        return ansi;


    }
};