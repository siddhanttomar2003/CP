class Dsu {
public:
    vector<int> parent, size;
    Dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findpar(int node) {
        if (parent[node] == node)
            return node;
        else
            return parent[node] = findpar(parent[node]);
    }
    void unions(int u, int v) {
        u = findpar(u);
        v = findpar(v);
        if (u == v)
            return;
        if (size[u] < size[v]) {
            size[v] += size[u];
            parent[u] = v;
        } else {
            size[u] += size[v];
            parent[v] = u;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 1;
        Dsu d(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int delRow[] = {0, -1, 0, 1};
                    int delCol[] = {-1, 0, 1, 0};
                    for (int k = 0; k < 4; k++) {
                        int nr = i + delRow[k];
                        int nc = j + delCol[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                            grid[nr][nc]) {
                            d.unions(nr * n + nc, i * n + j);
                            ans=max(ans,d.size[d.findpar(i*n+j)]);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Dsu nd(n * n);
                    nd = d;
                    int delRow[] = {0, -1, 0, 1};
                    int delCol[] = {-1, 0, 1, 0};
                    for (int k = 0; k < 4; k++) {
                        int nr = i + delRow[k];
                        int nc = j + delCol[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                            grid[nr][nc]) {
                            nd.unions(nr * n + nc, i * n + j);
                        }
                    }
                    ans = max(ans, nd.size[nd.findpar(i * n + j)]);
                }
            }
        }
        return ans;
    }
};