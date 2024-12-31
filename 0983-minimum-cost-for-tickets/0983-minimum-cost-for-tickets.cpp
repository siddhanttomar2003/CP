class Solution {
public:
    int dp[366][366];
    int cal(vector<int>&d, vector<int>&c, int valid_till, int i){
        if(i==d.size())return 0;
        if(dp[i][valid_till]!=-1)return dp[i][valid_till];
        int mini1=1e9;
        if(valid_till>=d[i]){
            mini1=cal(d,c,valid_till,i+1);
        }
        mini1=min(mini1,c[0]+cal(d,c,d[i],i+1));
        mini1=min(mini1,c[1]+cal(d,c,d[i]+6,i+1));
        mini1=min(mini1,c[2]+cal(d,c,d[i]+29,i+1));
        return dp[i][valid_till]=mini1;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return cal(days,costs,0,0);
    }
};