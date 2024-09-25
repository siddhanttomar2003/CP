#include<bits/stdc++.h>
using namespace std;


int main()
{
int n;
cin>>n;
map<int,int>mp1;
map<int,int>mp2;
vector<int> ans;
for(int i=0;i<n;i++){
  int op,a,b;cin>>op>>a>>b;
  if(op==0){
   if(mp1.find(a)==mp1.end()){
    mp1[a]=b;
   }
   else {
    mp1[a]=max(mp1[a],b);
   }
    if(mp2.find(b)==mp2.end()){
    mp2[b]=a;
   }
   else {
    mp2[b]=max(mp2[b],a);
   }
  }
  else{
    int maxi1=mp1.rbegin()->first;
    int maxi2=mp2.rbegin()->first;

    if(((maxi1<=a && mp1[maxi1]<=b) || (maxi2<=a && mp2[maxi2]<=b)) &&((maxi1<=b && mp1[maxi1]<=a) || (maxi2<=b && mp2[maxi2]<=a))) ans.push_back(true);
    else ans.push_back(false);
  }
} 

for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
return 0;
}