#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  vector<vector<char>>grid(n,vector<char>(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)cin>>grid[i][j];
    if(grid[0][0]=='*'){
        cout<<0<<endl;
        return 0;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!='*'){
                if(i==0 && j==0)continue;
                if(i==0)dp[i][j]=dp[i][j-1];
                else if(j==0)dp[i][j]=dp[i-1][j];
                else {
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j])%m;
                }
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
  
  
  return  0;
}