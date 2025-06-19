class Solution {
public:
    int dp[5001][2];
    int cal(vector<int>&p, int i , int op){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][op]!=-1)return dp[i][op];
        int maxi=0;
        if(op==0){
          maxi=max(maxi,-p[i]+cal(p,i+1,op^1));
          maxi=max(maxi,cal(p,i+1,op));
        }
        else {
            maxi=max(maxi,p[i]+cal(p,i+2,op^1));
            maxi=max(maxi,cal(p,i+1,op));
        }
        return dp[i][op]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return cal(prices,0,0);
    }
};
