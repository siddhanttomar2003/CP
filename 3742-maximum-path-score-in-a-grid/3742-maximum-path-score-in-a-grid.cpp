class Solution {
public:
    int dp[201][201][401];
    int cal(int i, int j, int n, int m, vector<vector<int>>&grid, int k){
        if(i == n - 1 && j == m - 1){
            if(grid[i][j]){
                if(k > 0)return grid[i][j];
                else return -1e9;
            }
            return 0;
        }
        if(dp[i][j][k] != -1)return dp[i][j][k];
        int mini = -1e9;
        if(grid[i][j]){
            if(k){
                if(i + 1 < n)mini = max(mini, grid[i][j] + cal(i + 1, j, n, m, grid, k - 1));
                if(j + 1 < m)mini = max(mini , grid[i][j] + cal(i, j + 1, n, m, grid, k - 1));
            }
        }
        else {
            if(i + 1 < n)mini = max(mini, cal(i + 1, j, n, m, grid, k));
                if(j + 1 < m)mini = max(mini , cal(i, j + 1, n, m, grid, k));
        }
        return dp[i][j][k] = mini;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        memset(dp, -1, sizeof(dp));
        if(k > 400)k = 400;
        int n = grid.size(), m = grid[0].size();
        int ans = cal(0, 0, n, m, grid, k);
        if(ans < 0)return -1;
        return ans;
    }
};