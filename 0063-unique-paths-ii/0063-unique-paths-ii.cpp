class Solution {
public:
    // int recur(vector<vector<int>>& obstacleGrid,int sr, int sc ,int n,int m ,vector<vector<int>>&dp){
    //       if(sr==n-1 && sc==m-1){
    //        return dp[sr][sc]=1;
    //       }
    //      if(sr==n || sc==m)return 0;
    //      if(obstacleGrid[sr][sc]==1){
    //        return dp[sr][sc]=0;
    //      }
    //      if(dp[sr][sc]!=0)return dp[sr][sc];
    //        dp[sr][sc]+=recur(obstacleGrid,sr+1,sc,n,m,dp);
    //      dp[sr][sc]+=recur(obstacleGrid,sr,sc+1,n,m,dp);
    //      return dp[sr][sc];
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // normal recursion
        // now memoize it
        // now tabaulate it

     
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1)return 0;
          vector<vector<int>>dp(n,vector<int>(m,0));
         dp[0][0]=1;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0)continue;
                else {
                    if(i>0)
                    dp[i][j]+=dp[i-1][j];
                    if(j>0)
                    dp[i][j]+=dp[i][j-1];
                }
            }
         }
         return dp[n-1][m-1];   
    }
};