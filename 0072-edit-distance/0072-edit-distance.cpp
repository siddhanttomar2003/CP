class Solution {
public:
    int dp[501][501];
    int cal(string &w1, string &w2, int i , int j, int n , int m){
        if(j == m)return n-i;
        if(i == n)return m-j;
        if(dp[i][j] != -1)return dp[i][j];
        int ways=1e9;
        if( w1[i] == w2[j]){
          ways = min(ways, cal(w1,w2,i+1,j+1,n,m));
        }
         ways = min(ways, 1 + cal(w1,w2,i+1,j,n,m));
         ways = min(ways, 1 + cal(w1,w2,i+1,j+1,n,m));
         return dp[i][j] = ways;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n=word1.size(),m=word2.size();
        return cal(word1,word2,0,0,n,m);
    }
};