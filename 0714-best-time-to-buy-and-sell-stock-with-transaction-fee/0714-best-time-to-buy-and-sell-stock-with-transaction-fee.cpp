class Solution {
public:
        int find_max(vector<int>& prices,vector<vector<int>> &dp,int i, int buy,int fee){
        // using take nottake
        if(i>=prices.size()){
            return 0;
        }
        int profit=INT_MIN;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
           profit=max(-prices[i]-fee+find_max(prices,dp,i+1,0,fee),find_max(prices,dp,i+1,1,fee));
        }
        else {
            profit=max(prices[i]+find_max(prices,dp,i+2,1,fee),find_max(prices,dp,i+1,0,fee));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
       int n=prices.size();
       vector<vector<int>>dp(n+1,vector<int>(2,0));
       for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
           if(buy) dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
           else dp[i][buy]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
        }
       }
       return dp[0][1];
    }
};