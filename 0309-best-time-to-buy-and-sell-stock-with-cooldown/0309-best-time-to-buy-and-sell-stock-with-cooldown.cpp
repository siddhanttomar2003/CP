class Solution {
public:
    int find_max(vector<int>& prices,vector<vector<int>> &dp,int i, int buy){
        // using take nottake
        if(i>=prices.size()){
            return 0;
        }
        int profit=INT_MIN;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
           profit=max(-prices[i]+find_max(prices,dp,i+1,0),find_max(prices,dp,i+1,1));
        }
        else {
            profit=max(prices[i]+find_max(prices,dp,i+2,1),find_max(prices,dp,i+1,0));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
       for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            if(buy)dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            else dp[i][buy]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
        }
       }
       return dp[0][1];
       
    }
};