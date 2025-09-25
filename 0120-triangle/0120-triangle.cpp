class Solution {
public:
    int dp[201][201];
    int min_sum(vector<vector<int>>& t, int i, int j){
        if (i == (int)t.size() - 1) return t[i][j];
        if (j < 0 || j >= (int)t[i].size()) return INT_MAX / 2;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int down = min_sum(t, i + 1, j);
        int downRight = min_sum(t, i + 1, j + 1);
        dp[i][j] = t[i][j] + min(down, downRight);
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 0; i < 201; ++i)
            for (int j = 0; j < 201; ++j)
                dp[i][j] = INT_MAX;
        return min_sum(triangle, 0, 0);
    }
};
