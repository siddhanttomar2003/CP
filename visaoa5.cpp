#include<bits/stdc++.h>


using namespace std;


int main()
{
 int n;cin>>n;
 string a;cin>>a;
 int m;cin>>m;
 string b;cin>>b;
 int carry=0;
 int i=n-1;int j=m-1;
 string ans="";
 while(i>=0 && j>=0){
    int curr=a[i]-48+b[j]-48;
   string temp=to_string(curr);
    reverse(temp.begin(),temp.end());
    ans+=temp;
    i--;j--;
 }
 while(i>=0){
      int curr=a[i]-48;
      string temp=to_string(curr);
      reverse(temp.begin(),temp.end());
    ans+=temp;
    i--;
 }
 while(j>=0){
      int curr=a[j]-48;
      string temp=to_string(curr);
      reverse(temp.begin(),temp.end());
      ans+=temp;
      j--;
 }

 reverse(ans.begin(),ans.end());
 cout<<ans<<endl;

return 0;
}