class Solution {
public:
     int minpath(vector<vector<int>>& grid, vector<vector<int>>&dp,int i,int j){
        if(i==grid.size()-1){
            int mini=INT_MAX;
            for(int c=0;c<grid.size();c++){
                if(c!=j)mini=min(mini,grid[i][c]);
            }
            return  dp[i][j]=mini;
        }
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        for(int c=0;c<grid.size();c++){
            if(c!=j){
               dp[i][j]= min(dp[i][j],grid[i][c]+minpath(grid,dp,i+1,c));
            }
        }
        return dp[i][j];
     }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)return grid[0][0];
        vector<vector<int>>dp(n,vector<int>(n+1,INT_MAX));
        minpath(grid,dp,0,n);
        return *min_element(dp[0].begin(),dp[0].end());
    }
};