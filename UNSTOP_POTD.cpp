#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main(){
     int t;
     cin>>t;
     while(t--){
         int n,q;
         cin>>n>>q;
         vector<int>v(n);
         for(int i=0;i<n;i++)cin>>v[i];
         vector<vector<int>>pre(n+1,vector<int>(32,0));
         for(int i=1;i<=n;i++){
            for(int j=0;j<32;j++){
                if(nums[i-1]&(1<<j)){
                    pre[i][j]=pre[i-1][j]+1;
                }
                else pre[i][j]=pre[i-1][j];
            }
         }
         
     }

  }
  
