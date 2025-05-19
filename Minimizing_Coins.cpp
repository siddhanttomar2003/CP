#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
typedef long long ll;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int>c(n);
  for(int i=0;i<n;i++)cin>>c[i];
  vector<int>dp(x+1,1e9);
  dp[0]=0;
  for(int i=0;i<n;i++){
      for(int j=1;j<=x;j++){
         if(c[i]<=j){
            dp[j]=min(dp[j],1+dp[j-c[i]]);
         }
      }
  }
  if(dp[x]==1e9)cout<<-1<<endl;
  else 
  cout<<dp[x]<<endl;
  
  return  0;
}