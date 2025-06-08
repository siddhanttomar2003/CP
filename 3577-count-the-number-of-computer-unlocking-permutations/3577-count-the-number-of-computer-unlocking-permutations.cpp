class Solution {
public:
    typedef long long ll;
    const int m=1e9+7;
    vector<ll>fac,inv;
    ll bin_expo(ll a, ll b){
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
    void build_fac(int n){
        fac.assign(n+1,0);
        inv.assign(n+1,0);
        fac[0]=1;
        for(ll i=1;i<=n;i++){
            fac[i]=(fac[i-1]*i)%m;
        }
        inv[n]=bin_expo(fac[n],m-2);
        for(ll i=n-1;i>0;i--){
            inv[i]=((i+1)*(inv[i+1]))%m;
        }
    }
    int countPermutations(vector<int>& c) {
         int mini=*min_element(c.begin()+1,c.end());
         if(mini<=c[0])return 0;
         int n=c.size();
         build_fac(n);
         ll ans=fac[n-1];
         
         return ans;
    }
};