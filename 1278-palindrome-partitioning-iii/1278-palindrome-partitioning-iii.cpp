class Solution {
public:
    int req[101][101];
    int dp[101][101];
    int build(string &s, int i, int j){
        if(i>j)return 0;
        if(i==j){
            return req[i][j]=0;
        }
        if(req[i][j]!=-1)return req[i][j];
        int count=0;
        if(s[i]==s[j]){
         count= build(s,i+1,j-1);
        }
        else {
            count = 1 + build(s,i+1,j-1);
        }
        build(s,i+1,j);build(s,i,j-1);
        return req[i][j]=count;
    }
    int cal(int i, int cuts, int n,int k){
        if(i>=n){
            if(cuts==k)return 0;
            return 1e9;
        }
        if(dp[i][cuts]!=-1)return dp[i][cuts];
        int mini=1e9;
        for(int l=i;l<n;l++){
            mini=min(mini,req[i][l]+cal(l+1,cuts+1,n,k));
        }
        return dp[i][cuts]=mini;
    }
    int palindromePartition(string s, int k) {
        int n=s.size();
        memset(req,-1,sizeof(req));
        memset(dp,-1,sizeof(dp));
        build(s,0,n-1);
        // for(int i=0;i<8;i++){
        //     for(int j=0;j<8;j++)cout<<req[i][j]<<" ";
        //     cout<<endl;
        // }
        return cal(0,0,n,k);
        // return 0;

    }
};