class Solution {
public:
    typedef long long ll;
    bool check(ll mid, vector<int> &w, int m){
        ll cal = 0;
        for(auto it : w){
            ll low = 0, high = m;
            ll ans = 0;
            while(low <= high){
                ll midd = low + (high - low) / 2;
                ll sum = (midd * (midd + 1)) / 2;
                if(sum * (ll)it <= mid){
                    ans = midd;
                    low = midd + 1;
                }
                else high = midd - 1;
            }
            cal += ans;
        }
        return cal >= m;
    }
    long long minNumberOfSeconds(int m, vector<int>& w) {
        ll s = 0, e = 1e16;
        ll ans = e;
        while(s <= e){
            ll mid = s + (e - s) / 2;
            if(check(mid, w, m)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};