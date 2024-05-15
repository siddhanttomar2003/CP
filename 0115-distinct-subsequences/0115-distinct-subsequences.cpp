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
        vector<vector<double>>dp(m+1,vector<double>(n+1,0));
        // if the string t gets exhausted then we will return 1 as discussed in memoization
        for(int i=0;i<=m;i++){
           dp[i][0]=1;
        }
        // now tabulating it just harder thing is to do find the base case rest are same
          for(int i=1;i<=m;i++){
             for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1])dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
             }
          }
         return (int)dp[m][n];
    }
};