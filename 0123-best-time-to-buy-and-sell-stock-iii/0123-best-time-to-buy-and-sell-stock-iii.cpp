class Solution {
public:
    int find_max(vector<int>& prices, vector<vector<int>>& dp, int i, int buy,
                 int count) {
        if (count == 2)
            return 0;
        if (i == prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = INT_MIN;
        if (buy) {
            profit = max(-prices[i] + find_max(prices, dp, i + 1, 0, count),
                         find_max(prices, dp, i + 1, 1, count));
        } else
            profit = max(prices[i] + find_max(prices, dp, i + 1, 1, count + 1),
                         find_max(prices, dp, i + 1, 0, count));
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // same as part-2 just adding count variable so we cannot perform
        // transaction more than twice
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return find_max(prices, dp, 0, 1, 0);
    }
};