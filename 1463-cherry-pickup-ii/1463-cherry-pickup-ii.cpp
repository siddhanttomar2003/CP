class Solution {
public:
    int max_cherry(vector<vector<int>>& grid, vector<vector<vector<int>>>&dp,int i,int j1,int j2){
        // base case 1
        if(j1<0 || j1==grid[0].size()|| j2<0 || j2==grid[0].size())return -1e8;
        if(i==grid.size()-1){
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        // now for one particular instant there are 9 possible direction in which they 
        // can go
             if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        for(int f=-1;f<=1;f++){
            for(int s=-1;s<=1;s++){
                if(j1==j2)
            dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+max_cherry(grid,dp,i+1,j1+f,j2+s));
            else dp[i][j1][j2]=max(dp[i][j1][j2],grid[i][j1]+grid[i][j2]+max_cherry(grid,dp,i+1,j1+f,j2+s));
            }
        }
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // represent everything in terms of indexes
        // we will require three indexes as one for row which is common for both robot
        // two are for thier col in respective rows
        // so we require a 3d dp here 
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        max_cherry(grid,dp,0,0,c-1);
        return dp[0][0][c-1];
    }
};