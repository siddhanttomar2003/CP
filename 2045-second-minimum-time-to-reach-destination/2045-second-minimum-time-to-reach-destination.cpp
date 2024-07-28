class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dis(n+1,1e9);
        vector<int>dis2(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        dis[1]=0;
        // dis2[1]=0;
        while(pq.size()>0){
            int par=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            for(int i=0;i<adj[par].size();i++){
                int curr_signal=wt/change;
                int child=adj[par][i];
                if(curr_signal%2==0){
                    if(dis[child]>wt+time){
                        dis2[child]=dis[child];
                        dis[child]=wt+time;
                        pq.push({dis[child],child});
                        pq.push({dis2[child],child});
                    }
                    else if(dis2[child]>wt+time && dis[child]<wt+time){
                        dis2[child]=wt+time;
                        pq.push({dis2[child],child});
                    }
                }
                else {
                    int rem=wt%change;
                    rem=change-rem;
                    if(dis[child]>wt+time+rem){
                        dis2[child]=dis[child];
                        dis[child]=wt+time+rem;
                        pq.push({dis[child],child});
                        pq.push({dis2[child],child});
                    }
                    else if(dis2[child]>wt+time+rem && dis[child]<wt+time){
                        dis2[child]=wt+time+rem;
                        pq.push({dis2[child],child});
                    }     
                }
            }
        }
        return dis2[n];
    }
    
};