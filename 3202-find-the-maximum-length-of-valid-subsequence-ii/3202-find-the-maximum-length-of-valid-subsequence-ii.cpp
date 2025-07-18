class Solution {
public:
    vector<vector<int>>dp;
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        dp.assign(n, vector<int>(k, 1));
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(dp[i][(nums[i] + nums[j]) % k] < 1 + dp[j][(nums[i] + nums[j]) % k]){
                    dp[i][(nums[i] + nums[j]) % k] = 1 + dp[j][(nums[i] + nums[j]) % k];            
                    maxi = max(maxi, dp[i][(nums[i] + nums[j]) % k]);
                }
            }
        }
        return maxi;

    }
};