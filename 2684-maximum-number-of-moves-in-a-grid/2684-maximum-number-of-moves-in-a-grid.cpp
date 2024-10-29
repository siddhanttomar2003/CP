class Solution {
public: 
    int cal(vector<vector<int>>&dp,map<pair<int,int>,int>&mp, vector<vector<int>>&grid,int i , int j, int last){
        if(i>=grid.size() || j>=grid[0].size() || i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        // if(mp.find({i,j})!=mp.end())return 0;
        int w1=0;int w2=0;int w3=0;
        // mp[{i,j}]++;
        if(i+1<grid.size() && j+1<grid[0].size() && grid[i+1][j+1]>last){
            w1=1+cal(dp,mp,grid,i+1,j+1,grid[i+1][j+1]);
        }
        if(i-1>=0 && j+1<grid[0].size() && grid[i-1][j+1]>last){
            w2=1+cal(dp,mp,grid,i-1,j+1,grid[i-1][j+1]);
        }
        if(i<grid.size() && j+1<grid[0].size() && grid[i][j+1]>last){
            w3=1+cal(dp,mp,grid,i,j+1,grid[i][j+1]);
        }
        // mp[{i,j}]--;
        // if(mp[{i,j}]==0)mp.erase({i,j});
      return dp[i][j]=max({w1,w2,w3});

    }
    int maxMoves(vector<vector<int>>& grid) {
        // convert grid into adj grid and then go as usual
        int m=grid.size();
        if(m==0)return 0;
        int n=grid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
         map<pair<int,int>,int>mp;
         int maxi=0;
         for(int i=0;i<m;i++){
           maxi=max(maxi,cal(dp,mp,grid,i,0,grid[i][0]));
         }
         return maxi;
         
    }
};