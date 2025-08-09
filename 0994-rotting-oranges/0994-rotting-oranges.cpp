class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n, vector<int>(m, 1e9));
        queue<vector<int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({0, i, j});
                    dis[i][j] = 0;
                }
            }
        }
        int maxi = 0;
        while(q.size() > 0){
            auto it = q.front();
            q.pop();
            int curr = it[0];
            int r = it[1];
            int c = it[2];
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for(int k  = 0; k < 4; k++){
                int n_r = r + delRow[k];
                int n_c = c + delCol[k];
                if(isValid(n_r, n_c, n, m) && grid[n_r][n_c] != 0 && dis[n_r][n_c] > curr + 1){
                    dis[n_r][n_c] = curr + 1;
                    maxi = max(maxi, curr + 1);
                    q.push({curr + 1, n_r, n_c});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    if(dis[i][j] == 1e9)return -1;
                }
            }
        }
        return maxi;
    }
};