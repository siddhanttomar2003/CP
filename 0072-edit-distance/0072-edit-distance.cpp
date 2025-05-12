class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
        //dp[i][j]-> number of different ways to make the string a equal to string b
        // if we take the string a to ith index and string b to jth index

        // where will it fail during the transition :-
        // when either one of this string completes or both of them completes we cannot call
        // for further transition

        //->base case:1(when string b finished )
        // ->base case:2 (when string a finished)
           
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int i=0;i<=m;i++)dp[0][i]=i;
        for(int i=1;i<=n;i++){
            char c=word1[i-1];
            for(int j=1;j<=m;j++){
               char d=word2[j-1];
               if(c==d){
                dp[i][j]=dp[i-1][j-1];
               }
               else {
                 dp[i][j]=min({1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]});
               }
            }
        }
        return dp[n][m];
    }
};