#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
typedef long long ll;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int>c(n);
  for(int i=0;i<n;i++)cin>>c[i];
  vector<int>dp(x+1,0);
  dp[0]=1;
  for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
       if(c[j]<=i){
        dp[i]=(dp[i]+dp[i-c[j]])%m;
       }
    }
  }
   cout<<dp[x]<<endl;
  
  return  0;
}