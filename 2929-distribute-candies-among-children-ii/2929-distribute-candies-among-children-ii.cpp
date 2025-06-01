typedef long long ll;
class Solution {
public:
    int Possible1(ll m, ll rhs, ll limit) {

        ll z=rhs-m;
        if(z>limit){
            return 1;
        }
        return 0;
    }
    

    long long distributeCandies(int n, int limit) {
        ll ans = 0;
        for (ll i = 0; i <= limit; i++) {
            ll x = i;
            ll rhs = n - i;
            ll l = 0, h = min(rhs,limit*1ll);
            ll end = h;
            ll start = -1;
            while (l <= h) {
                ll m = l + (h - l) / 2;
                ll signal=Possible1(m,rhs,limit);
                if(signal==1){
                    l=m+1;
                }
                else {
                    start=m;
                    h=m-1;
                }
                
            }
            if(start!=-1 && end>=start)
            ans += (end-start+ 1);
        }
        return ans;
    }
};