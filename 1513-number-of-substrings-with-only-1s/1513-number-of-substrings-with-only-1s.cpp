class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;
    int numSub(string s) {
        int n = s.size();
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll count = 0;
            while(i < n && s[i] == '1'){
                count++;
                i++;
            }
            ans = (ans + (count * (count + 1)) / 2ll) % mod;
        }
        return ans;
    }
};