class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // s1+s2 = sum;
        // s1-s2 = target
        // 2s1 = sum + target
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int f_tar= sum + target;
        if(f_tar & 1) return 0;
        int n = nums.size();
        f_tar /= 2;
        vector<int>dp(2001,0);
        dp[1000] = 1;
        for(int i = 0; i < n; i++){
            for(int j = f_tar; j >= 0 ;j--){
                if(nums[i] <= j){
                    dp[j+1000] += dp[j-nums[i]+1000];
                }
            }
        }
        return dp[f_tar+1000];
    }
};