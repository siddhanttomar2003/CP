class Solution {
public:
    int dp[1001][1001];
    int cal(vector<int>&nums, int tar, int last, int curr){
        if(curr == nums.size() - 1){
            int diff = abs(nums[curr] - nums[last]);
            if(diff <= tar)return 1;
            return -1e9;
        }
        if(dp[curr][last] != -1)return dp[curr][last];
        int diff = abs(nums[curr] - nums[last]);
        int steps = -1e9;
        if(diff <= tar){
            steps = 1 + cal(nums, tar, curr, curr + 1);
        }
        steps = max(steps, cal(nums, tar, last, curr + 1));
        return dp[curr][last] = steps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int res = cal(nums, target, 0, 1);
        if(res < 0)return -1;
        return res;
    }
};