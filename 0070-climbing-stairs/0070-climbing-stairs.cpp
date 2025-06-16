class Solution {
public:
    int dp[46];
    int cal(int n){
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=cal(n-1)+cal(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return cal(n);
    }
};
