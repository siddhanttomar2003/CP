class Solution {
public:
    int recur(int row,int col,int m,int n,vector<vector<int>> &dp){
        if(row>m || col >n)return 0;
        if(row==m && col==n){
            return dp[row][col]=1;
        }
        if(dp[row][col]!=0)return dp[row][col];
         dp[row][col]+= recur(row+1,col,m,n,dp);
      dp[row][col]+=  recur(row,col+1,m,n,dp);
      return dp[row][col];
         

    }
    int uniquePaths(int m, int n) {
        int ans=0;
        int row=0;int col=0;
        // now we memoize it
        vector<vector<int>>dp(m,vector<int>(n,0));
        recur(row,col,m-1,n-1,dp);
          return dp[0][0];
    }
};