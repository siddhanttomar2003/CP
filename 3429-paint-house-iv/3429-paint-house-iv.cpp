class Solution {
public:
    long long dp[100001][4][4];
    long long cal(vector<vector<int>>&cost, int i, int j, int last_ci,int last_cj){
        if(i>j)return 0;
        if(dp[i][last_ci][last_cj]!=-1)return dp[i][last_ci][last_cj];
        long long ans=1e18;
        for(int k=1;k<=3;k++){
            for(int l=1;l<=3;l++){
                 if(k!=l && k!=last_ci && l!=last_cj ){
                      ans=min(ans,cost[i][k-1]+cost[j][l-1]+cal(cost,i+1,j-1,k,l));
                 }
            }
        }
        return dp[i][last_ci][last_cj]=ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp,-1,sizeof(dp));
        return cal(cost,0,n-1,0,0);
    }
};