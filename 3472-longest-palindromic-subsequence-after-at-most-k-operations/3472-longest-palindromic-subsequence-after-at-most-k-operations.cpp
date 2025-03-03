class Solution {
public:
    int dp[200][200][201];
    int cal(string& a, int i, int j, int k) {
        if (i == j)
            return 1;
        if (i > j)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int maxi = 0;
        maxi = max(cal(a, i, j - 1, k), cal(a, i + 1, j, k));
        int min_diff = min(abs(a[j] - a[i]), 26 - (abs(a[j] - a[i])));
        if (k >= min_diff) {
            maxi = max(maxi, 2 + cal(a, i + 1, j - 1, k - min_diff));
        }
        return dp[i][j][k] = maxi;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        string a = s;
        memset(dp, -1, sizeof(dp));
        return cal(a, 0, n - 1, k);
    }
};