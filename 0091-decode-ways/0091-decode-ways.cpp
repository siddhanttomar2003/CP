class Solution {
public:
    int dp[101];
    int cal(string& s, int i, int n) {
        if (i >= n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        if (s[i] == '0')
            return 0;
        int ways = 0;
        if (s[i] == '1' || s[i] == '2') {
            ways += cal(s, i + 1, n);
            if (s[i] == '1' && i + 1 < n) {
                ways += cal(s, i + 2, n);
            }
            else if (s[i] == '2' && i+1 < n && s[i+1] <= '6'){
                ways += cal(s, i + 2, n);
            }
        }
        else ways += cal(s, i + 1, n);
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return cal(s, 0, n);
    }
};