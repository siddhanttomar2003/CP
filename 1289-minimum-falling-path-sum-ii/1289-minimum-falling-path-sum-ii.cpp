class Solution {
public:
    //  int minpath(vector<vector<int>>& grid, vector<vector<int>>&dp,int i,int j){
    //     if(i==grid.size()-1){
    //         int mini=INT_MAX;
    //         for(int c=0;c<grid.size();c++){
    //             if(c!=j)mini=min(mini,grid[i][c]);
    //         }
    //         return  dp[i][j]=mini;
    //     }
    //     if(dp[i][j]!=INT_MAX)return dp[i][j];
    //     for(int c=0;c<grid.size();c++){
    //         if(c!=j){
    //            dp[i][j]= min(dp[i][j],grid[i][c]+minpath(grid,dp,i+1,c));
    //         }
    //     }
    //     return dp[i][j];
    //  }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)return grid[0][0];
         vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
         for(int i=0;i<grid.size();i++){
            dp[0][i]=grid[0][i];
         }
         for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini=INT_MAX;
                for(int k=0;k<n;k++){
                    if(j==k)continue;
                    dp[i][j]=min(dp[i][j],grid[i][k]+dp[i-1][j]);
                }
            }
         }
         return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};