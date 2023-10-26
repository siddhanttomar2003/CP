#include<iostream>
using namespace std;


int main()
{
int n;
cin>>n;
string s;
cin>>s;
int count=1;
int ans=0;
for(int i=0;i<n-1;i++){
    if(s[i]=='x'&&s[i+1]=='x'){
count++;
if(count>=3)ans++;
    }
    else count=1;
  
}

cout<<ans<<endl;
return 0;
}