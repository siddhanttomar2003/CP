class Solution {
public:
    int dfs(int curr,int parent,int &count,vector<vector<int>> &adj){
        set<int>St;
        int total=0;
        if(adj[curr].size()==0){
            count++;
            return 0;
        }
        for(int i=0;i<adj[curr].size();i++){
            if(adj[curr][i]!=parent){
               int c=1;
               c+=dfs(adj[curr][i],curr,count,adj);
               total+=c;
               St.insert(c);
            }
        }
        if(St.size()<=1)count++;
            return total;
        // return 1+total;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
           int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        dfs(0,-1,count,adj);
        return count;

    }
};