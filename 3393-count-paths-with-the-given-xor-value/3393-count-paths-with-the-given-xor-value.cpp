class Solution {
public:
    int dp[301][301][16];
     int M=1e9+7;
    int cal(int i, int j, vector<vector<int>>&grid,int k , int curr, int n , int m){
        if(i==n-1 && j==m-1){
            curr^=grid[i][j];
            return curr==k;
        }
        if(i>=n || j>=m)return 0;
        curr^=grid[i][j];
        if(dp[i][j][curr]!=-1)return dp[i][j][curr];
        int t1=0,t2=0;
        t1=cal(i+1,j,grid,k,curr,n,m);
        t2=cal(i,j+1,grid,k,curr,n,m);
        return dp[i][j][curr]=(t1+t2)%M;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
       return cal(0,0,grid,k,0,n,m);
    }
};