class Solution {
public:
     int find_max(vector<int>& prices, vector<vector<vector<int>>>& dp, int i, int buy,
                 int count) {
        if (count == 0)
            return 0;
        if (i == prices.size())
            return 0;
        if (dp[i][buy][count] != -1)
            return dp[i][buy][count];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + find_max(prices, dp, i + 1, 0, count),
                         find_max(prices, dp, i + 1, 1, count));
        } else
            profit = max(prices[i] + find_max(prices, dp, i + 1, 1, count - 1),
                         find_max(prices, dp, i + 1, 0, count));
        return dp[i][buy][count] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=k;count++){
                    if(buy){
                        dp[i][buy][count]=max(-prices[i]+dp[i+1][0][count],dp[i+1][1][count]);
                    }
                    else {
                        dp[i][buy][count]=max(prices[i]+dp[i+1][1][count-1],dp[i+1][0][count]);
                    }
                }
            }
        }
        return dp[0][1][2];
        
    }
};