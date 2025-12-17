#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

typedef tree<
    pair<int,int>,               
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_multiset st;
        ll curr = 0;
        for (int i = 0; i < k; ++i) {
            ll greater = (ll)st.size() - st.order_of_key({nums[i], numeric_limits<int>::max()});
            curr += greater;
            st.insert({nums[i], i});
        }
        ll ans = curr;
        int i = 0, j = k;
        while (j < n) {
            ll lessCount = st.order_of_key({nums[i], numeric_limits<int>::min()});
            curr -= lessCount;
            st.erase({nums[i], i});
            ll greaterNew = (ll)st.size() - st.order_of_key({nums[j], numeric_limits<int>::max()});
            curr += greaterNew;
            st.insert({nums[j], j});
            ans = min(ans, curr);
            i++; j++;
        }
        return ans;
    }
};
