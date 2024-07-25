class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         vector<vector<int>> adj(n);
         for(int i=0;i<manager.size();i++){
            int u=manager[i];
            if(u!=-1)
            adj[u].push_back(i);
         }
        queue<pair<int,int>>q;
        vector<int>is_visited(n,0);
        q.push({headID,informTime[headID]});
        is_visited[headID]=1;
        int ans=0;
        while(q.size()>0){ 
                int par=q.front().first;
            int prev_time=q.front().second;
            q.pop();
            ans=max(ans,prev_time);
           for(int i=0;i<adj[par].size();i++){
             int child=adj[par][i];
             if(!is_visited[child]){
                int nxtime=prev_time+informTime[child];
                is_visited[child]=1;
                q.push({child,nxtime});
             }
           }
        }
        return ans;
    }
};