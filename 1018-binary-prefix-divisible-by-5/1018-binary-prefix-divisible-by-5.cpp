class Solution {
public:
    typedef long long ll;
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>ans(n, false);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum * 2) % 5;
            if(nums[i])sum = (sum + 1) % 5;
            if(sum == 0)ans[i] = true;
        }
        return ans;
    }
};