class Solution {
public:
     int recur(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(j>i)return INT_MAX;
        int same,right;
        if(dp[i][j]!=-1)return dp[i][j];
        same=   INT_MAX; right=INT_MAX;
        same=triangle[i][j]+recur(triangle,i+1,j,n,dp);
        right=triangle[i][j]+recur(triangle,i+1,j+1,n,dp);
        return dp[i][j]=min(same ,right);

       
     }
    int minimumTotal(vector<vector<int>>& triangle) {
        // first using recursion
        int i=0;int j=0;
        int n=triangle.size();
        // now using memoization
        vector<vector<int>>dp(n,vector<int>(n,-1));
        recur(triangle,i,j,n,dp);
        return dp[0][0];
        
    }
};