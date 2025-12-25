#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_multiset = tree<
    pair<T, int>,              
    null_type,
    less<pair<T, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class Solution {
public:
    typedef long long ll;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ll n = nums.size();
        ll ans = 0;
        ordered_multiset<int> st;
        ll curr = 0;
        st.insert({0, -1});
        for(int i = 0; i < n; i++){
            if(nums[i] == target)curr++;
            else curr--;
            ll u = st.order_of_key({curr, -1e9});
            ans += u;
            st.insert({curr, i});
        }
        return ans;
    }
};