class Solution {
public:
     int cal3(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&f){
        int n=f.size();
        if(i==j){
          return 0;
        }
        if(i==n-1)return -1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int tk1=0,tk2=0,tk3=0;
        if(i+1<n)  tk1=f[i][j]+cal3(i+1,j,dp,f);
        if(i+1<n && j+1<n)tk2=f[i][j]+cal3(i+1,j+1,dp,f);
        if(i+1<n && j-1>=0)tk3=f[i][j]+cal3(i+1,j-1,dp,f);
        return dp[i][j]=max({tk2,tk1,tk3});
    }
    int cal2(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&f){
        int n=f.size();
        if(i==j){
          return 0;
        }
        if(j==n-1)return -1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int tk1=0,tk2=0,tk3=0;
        if(i-1>=0 && j+1<n){
        tk1=f[i][j]+cal2(i-1,j+1,dp,f);
        }
        if(j+1<n){
        tk2=f[i][j]+cal2(i,j+1,dp,f);
        }
        if(i+1<n && j+1<n){
          tk3=f[i][j]+cal2(i+1,j+1,dp,f);
        }
        return dp[i][j]=max({tk2,tk1,tk3});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int child1=0;
        int n=fruits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)child1+=fruits[i][j];
            }
        }
         vector<vector<int>>dp1(n,vector<int>(n,-1));
         vector<vector<int>>dp2(n,vector<int>(n,-1));
        int child2=cal2(n-1,0,dp1,fruits);
        int child3=cal3(0,n-1,dp2,fruits);
        return child1+child2+child3;
    }
};