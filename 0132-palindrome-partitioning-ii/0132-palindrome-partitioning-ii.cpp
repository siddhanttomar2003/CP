class Solution {
public:
    int isPalen[2001][2001];
    int dp[2001];
    int build(string s, int i, int j) {
        if (i > j)
            return true;
        if (i == j)
            return isPalen[i][j] = true;
        if (isPalen[i][j] != -1)
            return isPalen[i][j];
        
        if (s[i] == s[j]) {
            isPalen[i][j] = build(s,i+1,j-1);
        }
        else {
            isPalen[i][j] = 0;
        }
        build(s,i+1,j);
        build(s,i,j-1);
        return isPalen[i][j];
    }
    int cal(int i, int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int cuts=1e9;
        for(int k=i;k<n;k++){
            if(isPalen[i][k]){
                cuts = min(cuts, 1 + cal(k+1,n) );
            }
        }
        return dp[i]=cuts;
    }
    int minCut(string s) {
        int n = s.size();
        memset(isPalen, -1, sizeof(isPalen));
        memset(dp, -1, sizeof(dp));
        build(s, 0, n - 1);
       return  cal(0,n) - 1;
    }
};