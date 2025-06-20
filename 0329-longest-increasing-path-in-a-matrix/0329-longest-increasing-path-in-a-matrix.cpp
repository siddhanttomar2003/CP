class Solution {
public:
    int dp[201][201];
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && j < m && i < n && j >= 0;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (dp[r][c] != -1)
            return dp[r][c];
        int count = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int n_r = r + delRow[i];
            int n_c = c + delCol[i];
            if (isValid(n_r, n_c, n, m) && grid[n_r][n_c] < grid[r][c]) {
                count = max(count, 1 + dfs(grid, n_r, n_c));
            }
        }
        return dp[r][c] = count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == -1) {
                    int curr = dfs(matrix, i, j);
                    if (curr > maxi) {
                        maxi = curr;
                    }
                }
            }
        }

        return maxi;
    }
};