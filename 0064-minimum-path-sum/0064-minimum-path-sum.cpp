class Solution {
public: 
    int recur(vector<vector<int>>& grid,int i,int j,int n, int m , int &curr,vector<vector<int>>&dp){
        if(i<0||i==n||j<0||j==m)return 4000000;
         if(i==n-1 && j==m-1){
            return grid[i][j];
         }
         if(dp[i][j]!=-1)return dp[i][j];
       int curr1=grid[i][j]+recur(grid,i+1,j,n,m,curr,dp);
        int  curr2=grid[i][j]+recur(grid,i,j+1,n,m,curr,dp);
        return dp[i][j]=min(curr1,curr2);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        int n=grid.size();int m=grid[0].size();
        int curr=0;
        vector<vector<int>>dp(n,vector<int> (m,-1));
        recur(grid,0,0,n,m,curr,dp);
        return dp[0][0];
    }
};