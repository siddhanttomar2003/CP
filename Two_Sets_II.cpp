#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m =1e9+7;
ll binomial_expo(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

int main(){
    ll n;
    cin>>n;
    ll sum=(n*(n+1))/2;
    if(sum&1){
        cout<<0<<endl;
        return 0;
    }
    ll tar=sum/2;
    vector<ll>dp(tar+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=tar;j>=1;j--){
            if(j-i>=0)dp[j]=(dp[j]+dp[j-i])%m;
        }
    }
    cout<<(dp[tar]*binomial_expo(2*1ll,m-2))%m<<endl;
    return 0;
}