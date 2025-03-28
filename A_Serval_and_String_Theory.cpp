#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll user_logic(int n, int p, std::vector<ll>& array);

int main() {
    int n, p;
    std::cin >> n >> p;
    std::vector<ll> array(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    ll result = user_logic(n, p, array);
    std::cout << result << std::endl;
    return 0;
}

ll user_logic(int n, int p, vector<ll>& array) {
  vector<ll>l(n,-1),r(n,-1);
  ll last=-1;
  for(ll i=0;i<n;i++){
     l[i]=last;
     if(array[i]!=0)last=i;
  }
  last=-1;
  ll ans=0;
  if(n>1){
  for(ll i=n-1;i>=0;i--){
    r[i]=last;
    if(array[i]!=0)last=i;
  }
  for(ll i=0;i<n;i++){
    if(array[i]==0){
        ll mini=1e9,maxi=-1;
        if(l[i]!=-1){
            mini=min(mini,i-l[i]);
            maxi=max(maxi,i-l[i]);
        }
        if(r[i]!=-1){
            mini=min(mini,r[i]-i);
            maxi=max(maxi,r[i]-i);
        }
        // cout<<mini<<" "<<maxi<<endl;
        if(maxi!=-1){
            ll full= p-maxi+1;
            if(i!=0 && i!=n-1)
            ans+=(4*1ll*full);
            else ans+=(2*1ll*full);
            ll avail_half=p-mini+1;
            ll half=full-avail_half;
            ans+=(2*1ll*half);
        }
        else {
            if(mini!=1e9)ans+=(p-mini+1)*2*1ll;
        }
    }
    else {
        ll count=0;
        if(i-1>=0 && array[i-1]!=0)count++;
        if(i+1<n && array[i+1]!=0)count++;
        if(i>0 && i<n-1){
            if(count==0)ans+=(p-1)*4*1ll;
            else if(count==1)ans+=(p-1)*4*1ll+2*1ll;
            else ans+=(p*4*1ll);
        }
        else if (count==0){
            ans+=(p-1)*2*1ll;
        }
        else ans+=(p*2*1ll);
    // cout<<count<<endl;
        
    }
    // cout<<ans<<" ";
  }
  }
  return ans;
}