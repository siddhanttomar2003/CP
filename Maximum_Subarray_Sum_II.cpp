#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long  ll;
typedef vector<ll> vl;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  vl v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  ll sum=0;
  ll maxi=0;
  map<ll,ordered_set>mp;
  
  mp[0].insert(-1);
  for(int i=0;i<n;i++){
    int curr=i;
    sum+=v[i];
    ll low=-1e15,high=1e15;
    while(low<=high){
        ll m= low+(high-low)/2;
        if(check())
    }
    mp[sum].insert(i);
  }
  
  cout<<maxi<<endl;
}