#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set                                                            \
    tree<int, null_type, less<int>, rb_tree_tag,                               \
         tree_order_statistics_node_update>

class Solution {
public:
    typedef long long ll;
    long long maxGCDScore(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        vector<int> two(n, 0);
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int count = 0;
            while (a % 2 == 0 && a > 1) {
                a /= 2;
                count++;
            }
            two[i] = count;
        }
        for (ll i = 0; i < n; i++) {
            ll gg = nums[i];
            unordered_map<ll, ll> mp;
            ll maxi = nums[i];
            for (ll j = i; j < n; j++) {
                mp[two[j]]++;
                maxi = max(maxi, (ll)nums[j]);
                gg = __gcd(gg, (ll)nums[j]);
                ll len = j - i + 1;
                ans = max(ans, (gg * len));
                ll count = 0;
                ll a = gg;
                while(a>1 && a%2==0){
                    a/=2;
                    count++;
                }
                if(mp[count]<=k)ans=max(ans,(2*1ll*gg*len));
            }
        }
        return ans;
    }
};