#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;cin>>n;
    vector<int>c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    vector<int>dp(1e5+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
      for(int j=1e5+1;j>=1;j--){
         if(c[i]<=j){
          dp[j]|=dp[j-c[i]];
         }
      }
    }
    vector<int>ans;
    for(int i=1;i<=1e5+1;i++){
      if(dp[i])ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
    return 0;
}