class Solution {
public:
    int minInsertions(string s) {
        // i have an intuition if we find out max palendromic subsequence
        // then i can just add (n-lps)
          string first=s;
        reverse(s.begin(),s.end());
        string second=s;
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int take=0;
                    int nottake=0;
                if(first[i-1]==second[j-1]){
                    take=1+dp[i-1][j-1];
                }
                else {
                      nottake=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=max(take,nottake);
                ans=max(ans,dp[i][j]);
            }
        }
        return s.length()-ans;
    }
};