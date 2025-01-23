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
        else
            return parent[node] = find_par(parent[node]);
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
        Dsu d(m * n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    d.unions(i,n+j);   
                }
            }
        }
        int count = 0;
        for(int i=0;i<m*n+1;i++){
            if(d.size[i]>2){
                count+=(d.size[i]-1);
            }
        }
        return count;
    }

};