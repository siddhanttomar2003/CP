#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  vector<long long>dp(n+1,0*1ll);
  dp[0]=1*1ll;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=min(i,6*1ll);j++){
       dp[i]=(dp[i]+dp[i-j])%m;
    }
  }
  cout<<dp[n]<<endl;
  return  0;
}