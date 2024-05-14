class Solution {
public:
     int find_ways(string s, string t, vector<vector<int>>&dp,int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;int nottake=0;int nottake2=0;
        if(s[i]==t[j]){
             take=find_ways(s,t,dp,i-1,j-1);
             nottake=find_ways(s,t,dp,i-1,j);
        }
        else nottake2=find_ways(s,t,dp,i-1,j);
      return   dp[i][j]=take+nottake+nottake2;
        
     }
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        // finding t in s as a subsequence
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return find_ways(s,t,dp,m-1,n-1);

    }
};