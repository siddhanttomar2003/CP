class Solution {
public:
    int minDistance(string word1, string word2) {
        // Thought process-> If we can also rearrange it then we can simply use the map
        // Idea is to find the max common subseq 

        // So the que changes into to find longest common subseq;
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int take=0;
                int nottake=0;
                if(word1[i-1]==word2[j-1])take=1+dp[i-1][j-1];
                else nottake=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=max(take,nottake);
            }
        }
        return (n-dp[n][m])+(m-dp[n][m]);
    }
};