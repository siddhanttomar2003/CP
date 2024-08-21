class Solution {
public:
    int cal(vector<vector<vector<int>>> &dp, vector<int> &piles, int i, int m,int turn){
        if(i>=piles.size())return 0;
        if(dp[i][m][turn]!= -1)return dp[i][m][turn];
        int take=turn==0?-1:INT_MAX;
        int sum=0;
        for(int j=1;j<=2*m;j++){
            if(i+j-1<piles.size()){
            if(turn==0){
                sum+=piles[i+j-1];
               take=max(take,sum+cal(dp,piles,i+j,max(m,j),turn^1));
            }
            else {
                take=min(take,cal(dp,piles,i+j,max(m,j),turn^1));
            }
            }
        }
        return dp[i][m][turn]=take;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(2,-1)));
        return cal(dp,piles,0,1,0);    
    }
};