#include<bits/stdc++.h>
using namespace std;


int main()
{
 int n,m;cin>>n>>m;
 vector<int>arr(n);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 vector<int>pattern(m);
 for(int i=0;i<m;i++){
    cin>>pattern[i];
 }
 vector<int>temp(n-1);
 for(int i=1;i<n;i++){
    if(arr[i]>arr[i-1])temp[i-1]=1;
    else if(arr[i]==arr[i-1])temp[i-1]=0;
    else temp[i-1]= -1;
 }
//  for(int i=0;i<n-1;i++)cout<<temp[i]<<" ";
//  cout<<endl;

 int ans=0;
 for(int i=0;i<n-1;i++){
    bool check=true;
    int k=0;
    if(i+m<n-1){
    for(int j=i;j<i+m-1;j++){
      if(temp[j]!=pattern[k]){
        check=false;
      }
      k++;
    }
    if(check)ans++;

    }
 }
 cout<<ans<<endl;
return 0;
}