#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long  ll;
typedef vector<ll> vl;
int main(){
  int n;
  cin>>n;
  vl v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  ll sum=accumulate(v.begin(),v.end(),0*1ll);
  ll maxi=*max_element(v.begin(),v.end());
  cout<<max(2*1ll*maxi,sum)<<endl;


  return 0;
}
