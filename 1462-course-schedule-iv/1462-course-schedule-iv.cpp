class Solution {
public:
    void dfs(vector<int>&vis,map<pair<int,int>,int>&mp,int start, int req,vector<vector<int>>&adj){
        vis[start]=1;
        mp[{req,start}]++;
        for(int i=0;i<adj[start].size();i++){
            int child=adj[start][i];
            if(!vis[child]){
               dfs(vis,mp,child,req,adj);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<vector<int>>adj(numCourses);
        for(auto it:pre){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
       map<pair<int,int>,int>mp;
       for(int i=0;i<numCourses;i++){
        vector<int>vis(numCourses,0);
        dfs(vis,mp,i,i,adj);
       }
       for(int i=0;i<queries.size();i++){
         int u=queries[i][0];
         int v=queries[i][1];
         if(mp.find({u,v})!=mp.end()){
            ans.push_back(true);
         }
         else ans.push_back(false);
       }
       return ans;
    }

};