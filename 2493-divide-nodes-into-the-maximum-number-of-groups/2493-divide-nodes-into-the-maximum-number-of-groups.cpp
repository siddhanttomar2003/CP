class Solution {
public:
    bool is_bipartite(vector<vector<int>>& adj, int start, vector<int>& color, vector<int>& vis, int curr_color) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        color[start] = curr_color;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int child : adj[node]) {
                if (!vis[child]) {
                    vis[child] = 1;
                    color[child] = 1 - color[node]; 
                    q.push(child);
                } else if (color[child] == color[node]) {
                    return false; 
                }
            }
        }
        return true;
    }

    int bfs(int start, vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> dist(adj.size(), -1);
        q.push(start);
        dist[start] = 0;
        int max_depth = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int child : adj[node]) {
                if (dist[child] == -1) {
                    dist[child] = dist[node] + 1;
                    max_depth = max(max_depth, dist[child]);
                    q.push(child);
                }
            }
        }
        return max_depth + 1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1);
        vector<int> vis(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (!is_bipartite(adj, i, color, vis, 0)) {
                    return -1; 
                }
            }
        }
        int max_groups = 0;
        vector<int> visited(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                queue<int> q;
                vector<int> component;
                q.push(i);
                visited[i] = 1;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = 1;
                            q.push(neighbor);
                        }
                    }
                }
                int local_max = 0;
                for (int node : component) {
                    local_max = max(local_max, bfs(node, adj));
                }
                max_groups += local_max;
            }
        }
        return max_groups;
    }
};
