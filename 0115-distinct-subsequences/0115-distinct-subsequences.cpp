class Solution {
public:
    int dp[1001][1001];
    int cal(string &s, string &t, int i, int j, int n, int m){
        if(j==m)return true;
        if(i==n)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        int ways=0;
        if(s[i]==t[j]){
            ways += cal(s,t,i+1,j+1,n,m);
            
        }

            ways += cal(s,t,i+1,j,n,m);
        
        return dp[i][j]=ways;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int m=t.size();
        return cal(s,t,0,0,n,m);
    }
};