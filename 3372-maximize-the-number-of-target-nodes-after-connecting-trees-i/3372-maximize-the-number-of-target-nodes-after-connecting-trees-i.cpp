class Solution {
public:
    int dfs(int start, vector<int>& visited, vector<vector<int>>& adj, int k) {
        if (k < 0)
            return 0;
        int curr = 1;
        visited[start] = 1;
        for (int i = 0; i < adj[start].size(); i++) {
            if (!visited[adj[start][i]]) {
                curr += dfs(adj[start][i], visited, adj, k - 1);
            }
        }
        return curr;
    }
    int cal(int start, vector<vector<int>>& adj, int n, int k) {
        vector<int> visited(n, 0);
        return dfs(start, visited, adj, k);
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int maxi1 = 0;
        for (int i = 0; i < edges1.size(); i++) {
            maxi1 = max({maxi1, edges1[i][0], edges1[i][1]});
        }
        int maxi2 = 0;
        for (int i = 0; i < edges2.size(); i++) {
            maxi2 = max({maxi2, edges2[i][0], edges2[i][1]});
        }
        vector<vector<int>> adj1(maxi1 + 1);
        vector<vector<int>> adj2(maxi2 + 1);

        for (int i = 0; i < edges1.size(); i++) {
            int a = edges1[i][0];
            int b = edges1[i][1];
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        for (int i = 0; i < edges2.size(); i++) {
            int a = edges2[i][0];
            int b = edges2[i][1];
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        vector<int> ans(maxi1 + 1);
        vector<int> first(maxi1 + 1);
        for (int i = 0; i < maxi1 + 1; i++) {
            first[i] = cal(i, adj1, maxi1 + 1, k);
            // cout << first[i] << " ";
        }
        int mm2=0;
        for(int i=0;i<maxi2+1;i++){
            mm2=max(mm2,cal(i,adj2,maxi2+1,k-1));
        }
        for(int i=0;i<maxi1+1;i++){
            ans[i]=mm2+first[i];
        }
        return ans;
       
    }
};