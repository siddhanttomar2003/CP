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
       // as it is given that you can buy it then immediately sell it on the same day.
       // so we can apply greedy
       int ans=0;
       int mini=prices[0];
       int profit=0;
       for(int i=1;i<prices.size();i++){
        profit=prices[i]-mini;
        mini=prices[i];
        if(profit>0)ans+=profit;
        profit=0;
       }
       return ans;
    }
};