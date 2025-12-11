class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;
    ll mod_inv(ll a, ll b){
        ll res = 1;
        while(b){
            if(b & 1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        ll ans = 0;
        map<int, int>mp;
        for(auto it : points)mp[it[1]]++;
        vector<ll>cal;
        ll sum = 0;
        for(auto it : mp){
            ll freq = it.second;
            ll ways = (freq * (freq - 1) * mod_inv(2, mod - 2)) % mod;
            cal.push_back(ways);
            sum = (sum + ways) % mod;
        }
        for(auto it : cal){
              sum = (sum - it + mod) % mod;
              ll curr = it;
              ans = (ans + curr * sum) % mod;
        }
        return ans;
    }
};