#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string a,b;
    cin>>a>>b;
    if(a.size()<b.size())swap(a,b);
    int n=a.size(),m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
    dp[0][0]=0;
    for(int i=0;i<=m;i++){
       dp[0][i]=i;
    }
    for(int i=0;i<=n;i++){
       dp[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        char c=a[i-1];
        for(int j=1;j<=m;j++){
            char d=b[j-1];
            if(c==d){
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            }
            else {
                dp[i][j]=min({dp[i][j],1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]});
            }
        }
    }
    cout<<dp[n][m]<<endl;
   
    return 0;
}