class Solution {
public:
    void bfs(vector<int>&dis, vector<vector<int>>&adj,int n,int start){
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        q.push({0,start});
        while(!q.empty()){
            int curr_dis=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(dis[it]>curr_dis+1){
                    dis[it]=curr_dis+1;
                    q.push({dis[it],it});
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)adj[i].push_back(edges[i]);
        }
        vector<int>dis1(n,1e9);
        vector<int>dis2(n,1e9);
        dis1[node1]=0,dis2[node2]=0;
        bfs(dis1,adj,n,node1);
        bfs(dis2,adj,n,node2);
        int ans=1e9;
        int ind=-1;
        for(int i=0;i<n;i++){
           if(max(dis1[i],dis2[i])<ans){
            ans=max(dis1[i],dis2[i]);
            ind=i;
           }
        }
        return ind;
    }
};