class Solution {
public:
    typedef long long ll;
    long long minEnd(int n, int x) {
        ll fixed = x;
        ll ans = x;
        ll num = n - 1;
        ll j = 0;
        for(ll i = 0; i < 64; i++){
            if(!(fixed & (1LL << i))){
                if(!(num & (1LL << j))){
                    j++;
                }
                else {
                    ans |= (1LL << i);
                    j++;
                }
            }
        }
        return ans;
    }
};