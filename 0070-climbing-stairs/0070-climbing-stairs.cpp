class Solution {
public:
     int find_ans(vector<int> &dp,int n){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=find_ans(dp,n-1)+find_ans(dp,n-2);
     }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return find_ans(dp,n);
    }
};