class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        int n=coins.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j){
                    dp[j]=min(dp[j],1+dp[j-coins[i]]);
                }
            }
        }
        if(dp[amount]==1e9)return -1;
        return dp[amount];
    }
};