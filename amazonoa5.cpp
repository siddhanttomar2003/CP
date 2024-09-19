#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
 int n;cin>>n;
 int x;cin>>x;
 long long ans=0;
 vector<int>v(n);
 for(int i=0;i<n;i++){
    int k;
    cin>>k;
    k%=x;
    v[i]=k;
    // cout<<v[i]<<" ";
 }
 sort(v.begin(),v.end());
 int i=0;int j=n-1;
 while(i<j){
    if(v[i]+v[j]==x){
        while(j>=i && v[j-1]==v[j]){
            ans++;
            j--;
        }
        i++;j--;
    }
    else if(v[i]+v[j]>x){
        j--;
    }
    else {
        i++;
    }
 }
 cout<<ans<<endl;
 

return 0;
}