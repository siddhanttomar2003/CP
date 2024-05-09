class Solution {
public:
    int find_max(string &text1, string &text2, int index1, int index2,vector<vector<int>> &dp){
        if(index1==0 && index2==0){
           if(text1[index1]==text2[index2])return 1;
           return 0;
        }
        if(index1<0 || index2<0)return 0;
        // if both are same
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        int take=0;
        if(text1[index1]==text2[index2])take=1+find_max(text1,text2,index1-1,index2-1,dp);
        // else there are two conditions whether we go through one direction
        int nottake1=0;
       if(text1[index1]!=text2[index2] )
        nottake1=find_max(text1,text2,index1-1,index2,dp);
        int nottake2=0;
        if(text1[index1]!=text2[index2] )
        nottake2=find_max(text1,text2,index1,index2-1,dp);
        return dp[index1][index2]=max(take,max(nottake1,nottake2));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int index1=text1.size();
        int index2=text2.size();
        vector<vector<int>>dp(index1,vector<int>(index2,-1));
         return find_max(text1,text2,index1-1,index2-1,dp);
    }
};