class Solution {
public:
    int dp[501][501];
    int cal(string  &word1,string &word2, int i, int j){
        if(i==word1.size() && j==word2.size())return 0;
        if(i==word1.size() || j==word2.size())return max(word1.size()-i,word2.size()-j);
        if(dp[i][j]!=-1)return dp[i][j];
        int ways=1e8;
        if(word1[i]==word2[j]){
            ways=cal(word1,word2,i+1,j+1);
        }
        else  ways=min(ways,1+cal(word1,word2,i+1,j+1));
        ways=min(ways,1+cal(word1,word2,i+1,j));
        ways=min(ways,1+cal(word1,word2,i,j+1));
       
        
        return dp[i][j]=ways;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return cal(word1,word2,0,0);
    }
};