#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int n, int x) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, INT_MAX));

    // Initialize the first column to 0, since no coins are needed to make sum 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            // If we do not take the i-th coin
            dp[i][j] = dp[i - 1][j];
            // If we take the i-th coin
            if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
    }

    // If dp[n][x] is still INT_MAX, it means it's not possible to make sum x
    return dp[n][x] == INT_MAX ? -1 : dp[n][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int result = minCoins(coins, n, x);
    cout << result << endl;

    return 0;
}
