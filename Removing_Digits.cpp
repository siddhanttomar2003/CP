#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  vector<int>dp(n+1,1e9);
  dp[0]=0;
  for(int i=1;i<=n;i++){
     vector<int>temp;
     int num=i;
     while(num>0){
        temp.push_back(num%10);
        num/=10;
     }
     for(int j=0;j<temp.size();j++){
          dp[i]=min(dp[i],(1+dp[i-temp[j]])%m);
     }
  }
  cout<<dp[n]<<endl;
  
  
  return  0;
}