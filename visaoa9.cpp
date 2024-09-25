#include<bits/stdc++.h>
using namespace std;


int main()
{
 int n1,n2;
 cin>>n1>>n2;
 vector<int>a(n1);
 vector<int>b(n2);
 unordered_map<int,int>mp;
 
 for(int i=0;i<n1;i++){
    cin>>a[i];
    mp[a[i]]++;
 }
 for(int i=0;i<n2;i++)cin>>b[i];
 int op;cin>>op;
 while(op--){
    int t;cin>>t;
    if(t==0){
        int i,x;cin>>i>>x;
        b[i]+=x;
    }
    else {
          int x;cin>>x;
          int ans=0;
          for(int i=0;i<n2;i++){
            int req=x-b[i];
            if(mp.find(req)!=mp.end()){
                ans+=(mp[req]);
            }
          }
          cout<<ans<<endl;
    }

 }
return 0;
}