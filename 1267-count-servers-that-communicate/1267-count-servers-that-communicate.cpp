class Dsu {
public:
    vector<int> parent, size;

    Dsu(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find_par(parent[node]); // Path compression
    }

    void unions(int u, int v) {
        u = find_par(u);
        v = find_par(v);
        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        Dsu dsu(n * m);

        // Connect servers in rows and columns
        for (int i = 0; i < n; i++) {
            int firstServer = -1;
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    if (firstServer == -1)
                        firstServer = i * m + j;
                    else
                        dsu.unions(firstServer, i * m + j);
                }
            }
        }

        for (int j = 0; j < m; j++) {
            int firstServer = -1;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    if (firstServer == -1)
                        firstServer = i * m + j;
                    else
                        dsu.unions(firstServer, i * m + j);
                }
            }
        }

        // Count connected components with more than one server
        unordered_map<int, int> componentCount;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int root = dsu.find_par(i * m + j);
                    componentCount[root]++;
                }
            }
        }

        int count = 0;
        for (auto& [root, size] : componentCount) {
            if (size > 1)
                count += size; // Only count servers in connected components
        }

        return count;
    }
};
