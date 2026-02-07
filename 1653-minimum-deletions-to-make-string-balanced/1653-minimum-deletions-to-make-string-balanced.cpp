class Solution {
public:
    int dp[100001][3];
    int cal(string &s, int i, int n, int state){
        if(i == n)return 0;
        if(dp[i][state] != -1)return dp[i][state];
        int ans = 1e9;
        if(state == 0){
            ans = min(ans, 1 + cal(s, i + 1, n, state));
            if(s[i] == 'a')ans = min(ans, cal(s, i + 1, n, 1));
            else if(s[i] == 'b')ans = min(ans, cal(s, i + 1, n, 2));
        }
        else if(state == 1){
            if(s[i] == 'a')ans = min(ans, cal(s, i + 1, n, 1));
            else if(s[i] == 'b')ans = min(ans, cal(s, i + 1, n, 2));
            ans = min(ans, 1 + cal(s, i + 1, n, state));
        }
        else {
            if(s[i] == 'b')ans = min(ans, cal(s, i + 1, n, 2));
            ans = min(ans, 1 + cal(s, i + 1, n, state));
        }
        return dp[i][state] = ans;
    }
    int minimumDeletions(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return cal(s, 0, n, 0);
    }
};