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
        int n=grid.size();int m=grid[0].size();
        if(n==1 && m==1)return grid[0][0];
        // now tabulation

        vector<vector<int>>dp(n,vector<int> (m,-1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr1=0;
                int curr2=0;
                if(i==0  && j==0)continue;
                else {
                    if(i-1>=0)
                     curr1+=grid[i][j]+dp[i-1][j];
                     if(j-1>=0)
                     curr2+=grid[i][j]+dp[i][j-1];
                     if(curr1==0)dp[i][j]=curr2;
                     else if(curr2==0)dp[i][j]=curr1;
                     else dp[i][j]=min(curr1,curr2);
                }
            }
        }
        return dp[n-1][m-1];
    }
};