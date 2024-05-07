class Solution {
public:
    int recur(vector<int> &coins, vector<vector<int>> &dp,int i,int amount){
        if(amount==0)return 0;
        if(amount<0)return 1e8;
        if(i==0){
            if(amount%coins[0]==0)return amount/coins[0];
            return 1e8;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        
          int take1=1+recur(coins,dp,i,amount-coins[i]);
        int nottake=recur(coins,dp,i-1,amount);
        return dp[i][amount]=min(take1,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=recur(coins,dp,n-1,amount);
        if(ans==1e8)return -1;
         return ans;
    }
};