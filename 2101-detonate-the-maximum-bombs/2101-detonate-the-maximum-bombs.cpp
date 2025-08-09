
vector<vector<int>>adj;
void dfs(int node, vector<int>&vis, int &count){
    vis[node] = 1;
    count++;
    for(auto it : adj[node]){
        if(!vis[it])dfs(it, vis, count);
    }
}
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        adj.resize(n);
        adj.clear();
        for(int i = 0; i < n; i++){
            double x1 = bombs[i][0];
            double y1 = bombs[i][1];
            double r1 = bombs[i][2];
            for(int j = i + 1; j < n; j++){
                double x2 = bombs[j][0];
                double y2 = bombs[j][1];
                double r2 = bombs[j][2];
                double dis = sqrt(pow(abs(y2 - y1), 2) + pow(abs(x2 - x1), 2));
                if(r1 >= dis)adj[i].push_back(j);
                if(r2 >= dis)adj[j].push_back(i);
            }
        }
        
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            vector<int>vis(n, 0);
            dfs(i, vis, count);
            maxi = max(maxi, count);
        }
        return maxi;
    }
};