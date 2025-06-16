class Solution {
public:
    int dp[1001];
    int cal(vector<int>&c, int i, int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=min(c[i]+cal(c,i+1,n),c[i]+cal(c,i+2,n));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return min(cal(cost,0,n),cal(cost,1,n));
    }
};