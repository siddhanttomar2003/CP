class Solution {
public:
    typedef long long ll;
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = n - 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int curr = i;
            int idx = upper_bound(nums.begin(), nums.end(), k * 1ll * nums[i]) - nums.begin();
            curr += n - idx;
            mini = min(mini, curr);
        }
        return mini;
    }
};