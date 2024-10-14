
class Solution {
public:
     int m=1e9+7;
    int cal(vector<vector<vector<int>>>&dp, vector<int>&temp, int i, int last, int curr_score){
         if(i==temp.size()){
           int ori=curr_score-1000;
           if(ori>0)return 1;
           return 0;
         }
         if(dp[i][curr_score][last]!=-1)return dp[i][curr_score][last];
         int curr_type=temp[i];
         int w1=0;
         for(int j=0;j<3;j++){
             if(j!=last){
                if(curr_type==0 && j==1 || curr_type==1 && j==2 || curr_type==2 && j==0){
                    w1=(w1+cal(dp,temp,i+1,j,curr_score+1))%m;
                }
                else if(curr_type==j){
                    w1=(w1+cal(dp,temp,i+1,j,curr_score))%m;
                }
                else {
                    w1=(w1+cal(dp,temp,i+1,j,curr_score-1))%m;
                }
             }
         }
         return dp[i][curr_score][last]=w1;
    }
    int countWinningSequences(string s) {
        int ans=0;
        int n=s.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            if(s[i]=='F')temp[i]=0;
            if(s[i]=='W')temp[i]=1;
            if(s[i]=='E')temp[i]=2;
        }
        vector<vector<vector<int>>>dp(1000,vector<vector<int>>(2000,vector<int>(4,-1)));
        return cal(dp,temp,0,3,1000);
    }
};