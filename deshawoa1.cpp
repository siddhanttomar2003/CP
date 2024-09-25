#include<bits/stdc++.h>


using namespace std;


int main()
{
 int n,val;cin>>n>>val;
 vector<int>temp(n);
 map<int,vector<int>>mp;
 for(int i=0;i<n;i++){
        cin>>temp[i];
        mp[temp[i]].push_back(i);
 }
 vector<int>v(n+1,0);
 for(int i=1;i<=n;i++){
    if(temp[i-1]==val){
       v[i]=v[i-1]+1;
    }
    else v[i]=v[i-1];
 }
//  for(int i=0;i<=n;i++)cout<<v[i]<<" ";
//  cout<<endl;
 
 int ans=v[n];
 for(auto it:mp){
    if(it.first!=val){
        vector<int>c=it.second;
        for(int i=0;i<c.size();i++){
            ans=max(ans,i+1+(v[n]-v[c[i]-1]));
        }
    }
 }
 cout<<ans<<endl;
 

 
return 0;
}