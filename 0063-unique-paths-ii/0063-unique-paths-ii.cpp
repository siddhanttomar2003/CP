class Solution {
public:
    int recur(vector<vector<int>>& obstacleGrid,int sr, int sc ,int n,int m ,vector<vector<int>>&dp){
          if(sr==n-1 && sc==m-1){
           return dp[sr][sc]=1;
          }
         if(sr==n || sc==m)return 0;
         if(obstacleGrid[sr][sc]==1){
           return dp[sr][sc]=0;
         }
         if(dp[sr][sc]!=0)return dp[sr][sc];
           dp[sr][sc]+=recur(obstacleGrid,sr+1,sc,n,m,dp);
         dp[sr][sc]+=recur(obstacleGrid,sr,sc+1,n,m,dp);
         return dp[sr][sc];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // normal recursion
        // now memoize it
     
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
          vector<vector<int>>dp(n,vector<int>(m,0));
      return  recur(obstacleGrid,0,0,n,m,dp);
        
    }
};