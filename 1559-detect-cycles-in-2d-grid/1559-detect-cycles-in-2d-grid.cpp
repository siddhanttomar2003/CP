class Solution {
public:
    bool valid(int r, int c, int n, int m){
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    bool cal(vector<vector<char>> &grid, vector<vector<int>>&vis, char co, int i, int j, int n, int m){
        queue<vector<int>>q;
        q.push({i, j, -1, -1});
        vis[i][j] = 1;
        while(q.size() > 0){
            auto it = q.front();
            q.pop();
            int r = it[0], c = it[1];
            int prev_r = it[2], prev_c = it[3];
            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int n_r = r + delRow[i];
                int n_c = c + delCol[i];
                if(valid(n_r, n_c, n, m) && (grid[n_r][n_c] == co) && !(prev_r == n_r && prev_c == n_c)){
                    if(vis[n_r][n_c])return true;
                    else {
                        vis[n_r][n_c] = 1;
                        q.push({n_r, n_c, r, c});
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        bool f = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    f |= cal(grid, vis, grid[i][j], i, j, n, m);
                }
            }
        }
        return f;
    }
};