#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


int main()
{
int n,k;
cin>>n>>k;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
//brute 
int l=0;
for(int i=0;i<n;i++){
int sum=0;
for(int j=i;j<n;j++){
    sum+=v[j];
    if(sum==k){
     l=max(l,j-i+1);
     break;
    }
}
}
cout<<l;
return 0;
}