#include<iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
int hash[256]={0};
for(int i=0;i<n;i++){
    if(s[i]<97){
        hash[s[i]+32]++;
    }
    else
    hash[s[i]]++;
   
}
int flag=1;
for(int i=97;i<=122;i++){
    if(hash[i]==0){
        flag=0;
        break;
}
}
if(flag==0)cout<<"NO"<<endl;
else cout<<"YES"<<endl;



return 0;
}