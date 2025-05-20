typedef long long ll;
const int mod=1e9+7;
class Solution {
public:
    vector<ll>fac,inv;
    ll mod_expo(ll a, ll p){
        ll res=1;
        while(p>0){
            if(p&1)res=(res*a)%mod;
            a=(a*a)%mod;
            p>>=1;
        }
        return res;
    }
    void pre_fac(int n){
        fac.resize(n+1,0);
        inv.resize(n+1,0);
        fac[0]=1;
        for(ll i=1;i<=n;i++){
            fac[i]=(fac[i-1]*i)%mod;
        }
        inv[n]=mod_expo(fac[n],mod-2);
        for(ll i=n;i>0;i--){
           inv[i-1]=(inv[i]*i)%mod;
        }
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<ll>freq(26,0);
        for(auto it:s)freq[it-97]++;
        sort(freq.rbegin(),freq.rend());
        ll avail=0;
        for(auto it:freq)if(it>0)avail++;
        if(k>avail)return 0;
        map<ll,ll>f_f;
        for(auto it:freq)f_f[it]++;
        ll options=0;
        options=f_f[freq[k-1]];
        ll used=0;
        ll pos=-1;
        for(int i=0;i<k;i++){
            if(freq[i]==freq[k-1]){
                pos=i;
                used=k-i;
                break;
            }
        }
        pre_fac(options);
        ll last=(((fac[options]*inv[used])%mod)*inv[options-used])%mod;
        ll ans=1;
        for(int i=0;i<pos;i++){
              ans=(ans*freq[i])%mod;
        }
        for(int i=pos;i<k;i++){
            ans=(ans*freq[i])%mod;
        }
        ans=(ans*last)%mod;
        return ans;
    }
};