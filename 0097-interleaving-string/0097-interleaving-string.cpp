class Solution {
public:
    int dp[101][101][201];
    int cal(string &s1, string &s2, string &s3, int i , int j , int k ){
        if(k == s3.size() && i == s1.size() && j == s2.size())return 1;
        if(k == s3.size())return 0;
        if(dp[i][j][k] != -1)return dp[i][j][k];
        string temp1="",temp2="",temp3="";
        int s_i=i,s_j=j,s_k=k;
        int pos = 0;
        while(s_k < s3.size()){
            if(s_i<s1.size()){
                temp1+=s1[s_i];
                s_i++;
            }
            if(s_j<s2.size()){
                temp2+=s2[s_j];
                s_j++;
            }
            if(s_k<s3.size())temp3+=s3[s_k];
            if(temp3 == temp1){
                pos |= cal(s1,s2,s3,s_i,j,s_k+1);
            }
            if(temp3 == temp2){
                pos|= cal(s1,s2,s3,i,s_j,s_k+1);
            }
            s_k++;
        }
        return dp[i][j][k]=pos;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return cal(s1,s2,s3,0,0,0);
    }
};