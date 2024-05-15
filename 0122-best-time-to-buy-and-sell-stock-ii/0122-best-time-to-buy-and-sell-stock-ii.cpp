class Solution {
public:
    int find_max(vector<int>& prices,vector<vector<int>> &dp,int i, int buy){
        // using take nottake
        if(i==prices.size()){
            return 0;
        }
        int profit=INT_MIN;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
           profit=max(-prices[i]+find_max(prices,dp,i+1,0),find_max(prices,dp,i+1,1));
        }
        else {
            profit=max(prices[i]+find_max(prices,dp,i+1,1),find_max(prices,dp,i+1,0));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        // remembering one thing we cannot buy after buy or sell after sell
        // so if we buy we need to sell at any day after this
        // so trying all possible ways
        // using recursion
        int n=prices.size();
        int i=0;
        int buy=1; // so current state is buy then we can buy else we need to sell
        vector<vector<int>>dp(n,vector<int>(2,-1));
         return find_max(prices,dp,i,buy);
    }
};