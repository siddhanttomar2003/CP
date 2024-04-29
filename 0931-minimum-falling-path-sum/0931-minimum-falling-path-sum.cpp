class Solution {
public:
     int minpath(vector<vector<int>> & matrix,vector<vector<int>>&dp,int c,int i){
        if(i==matrix.size()-1)return matrix[i][c];
        if(dp[i][c]!=-1)return dp[i][c];
        int same,left,right;
        same=INT_MAX;left=INT_MAX;right=INT_MAX;
        same=matrix[i][c]+minpath(matrix,dp,c,i+1);
        if(c-1>=0)
        left=matrix[i][c]+minpath(matrix,dp,c-1,i+1);
        if(c+1<matrix.size())right=matrix[i][c]+minpath(matrix,dp,c+1,i+1);
        dp[i][c]=min(same,min(left,right));
        return dp[i][c];
     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,minpath(matrix,dp,i,0));
        }
        return mini;

    }
};