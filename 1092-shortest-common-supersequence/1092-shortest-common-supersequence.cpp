class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // WE HAVE TO USE LCS TABLE
        // OBS:- the lcs of both string must come in the answer only once 
        // then we will traverse across the dp table to find the answer string
        int m=str1.length();int n=str2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int take=0;
                int nottake=0;
                if(str1[i-1]==str2[j-1])take=1+dp[i-1][j-1];
                else nottake=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=max(take,nottake);
            }
        }
        string ans="";
        int i=m;int j=n;
        while(i>0 && j>0){
           if(str1[i-1]==str2[j-1]){
            ans+=str1[i-1];
            i--;j--;
           }
           else {
            if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else {
                ans+=str2[j-1];
                j--;
            }
           }
        }
        while(i>0){
            ans+=str1[i-1];i--;
        }
        while(j>0){
            ans+=str2[j-1];j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};