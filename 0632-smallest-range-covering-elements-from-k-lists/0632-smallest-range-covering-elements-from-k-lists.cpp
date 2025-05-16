class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int range = 1e9;
        set<pair<int, int>> st;
        int start = -1, end = -1;
        int n = nums.size(), k = nums[0].size();
        for (int i = 0; i < n; i++) {
            st.insert({nums[i][0], i});
        }
        while (true) {
            int curr_min = st.begin()->first;
            int ind_s = st.begin()->second;
            int curr_max = st.rbegin()->first;
            int ind_e = st.rbegin()->second;
            int curr_range = curr_max - curr_min;
            if (curr_range < range) {
                range = curr_range;
                start = curr_min;
                end = curr_max;
            }
            int it =
                upper_bound(nums[ind_s].begin(), nums[ind_s].end(), curr_min) -
                nums[ind_s].begin();
            int size = nums[ind_s].size();
            st.erase({curr_min,ind_s});
            if (it == size)
                break;
            st.insert({nums[ind_s][it], ind_s});
        }
        return {start, end};
    }
};