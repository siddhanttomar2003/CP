class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int i, int state) {
        if (i == 0) return state == 0 ? 1 : 0;
        if (i == 1) return state == 0 ? 1 : 0;
        if (dp[i][state] != -1) return dp[i][state];

        long long res = 0;

        if (state == 0) {
            res = ((solve(i - 1, 0) + solve(i - 2, 0))%MOD + (solve(i - 1, 1) + solve(i - 1, 2))%MOD) % MOD;
        } else if (state == 1) {
            res = (solve(i - 1, 2) + solve(i - 2, 0)) % MOD;
        } else if (state == 2) {
            res = (solve(i - 1, 1) + solve(i - 2, 0)) % MOD;
        }

        return dp[i][state] = res;
    }

    int numTilings(int n) {
        dp.assign(n + 2, vector<int>(3, -1));
        return solve(n, 0);
    }
};
