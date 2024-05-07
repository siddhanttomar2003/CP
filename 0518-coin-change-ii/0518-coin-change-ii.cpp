class Solution {
public:
     int total_combinations(vector<int> &coins, vector<vector<int>> &dp,int amount, int i){
        if(amount==0)return 1;
        if(amount<0)return 0;
        if(i==0){
            if(amount%coins[0]==0)return 1;
            return 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take= total_combinations(coins,dp,amount-coins[i],i);
        int nottake=total_combinations(coins,dp,amount,i-1);
         return dp[i][amount]=take+nottake;
     }
    int change(int amount, vector<int>& coins) {
        // using memoization and recursion
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
           return total_combinations(coins,dp,amount,n-1);
    }
};