class Solution {
public:
    void bfs2(vector<vector<int>>& adj, vector<int>& first, int n) {
        vector<int> visited(n + 1, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        int odd = 0;
        int even = 0;
        visited[0] = 1;
        while (q.size() > 0) {
            int par = q.front().first;
            int l = q.front().second;
            if (l & 1)
                odd++;
            else
                even++;
            q.pop();
            for (int i = 0; i < adj[par].size(); i++) {
                int child = adj[par][i];
                if (!visited[child]) {
                    visited[child] = 1;
                    q.push({child, l + 1});
                }
            }
        }
        q.push({0, 0});
        vector<int> vis(n + 1, 0);
        while (q.size() > 0) {
            int par = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l%2==0){
               first[par]=even;
            }
            else first[par]=odd;
            for (int i = 0; i < adj[par].size(); i++) {
                int child = adj[par][i];
                if (!vis[child]) {
                    vis[child] = 1;
                    q.push({child, l + 1});
                }
            }
        }
    }
    int bfs(vector<vector<int>>& adj, int n) {

        vector<int> visited(n + 1, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        int odd = 0;
        int even = 0;
        visited[0] = 1;
        while (q.size() > 0) {
            int par = q.front().first;
            int l = q.front().second;
            if (l & 1)
                odd++;
            else
                even++;
            q.pop();
            for (int i = 0; i < adj[par].size(); i++) {
                int child = adj[par][i];
                if (!visited[child]) {
                    visited[child] = 1;
                    q.push({child, l + 1});
                }
            }
        }
        return max(odd, even);
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
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
        queue<pair<int, int>> q;
        q.push({0, 0});
        int level = 0;
        int odd = 0;
        int even = 0;
        int ans2 = 0;
        ans2 = bfs(adj2, maxi2 + 1);
        vector<int> first(maxi1 + 1);
        bfs2(adj1, first, maxi1 + 1);
        for(int i=0;i<maxi1+1;i++){
            first[i]+=ans2;
        }
        return first;
    }
};