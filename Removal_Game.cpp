#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5005;
ll dp[N][N];
ll cal(int i, int j, vector<ll>&c){
    if(i==j)return c[i];
    else if(j-i==1)return max(c[i],c[j]);
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]= max((c[i]+min(cal(i+2,j,c),cal(i+1,j-1,c))),(c[j]+min(cal(i+1,j-1,c),cal(i,j-2,c))));
}
int main(){
    int n;cin>>n;
    vector<ll>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<cal(0,n-1,c)<<endl;
    return 0;
}