class Solution {
public:
    typedef long long ll;
    ll dp[40001][3];
    ll cal(vector<int>&nums, int i, int n, ll s){
        if(i == n){
            return s % 3 == 0 ? 0 : -1e9;
        }
        if(dp[i][s % 3] != -1)return dp[i][s % 3];
        ll ans = 0;
        ans = nums[i] + cal(nums, i + 1, n, s + nums[i]);
        ans = max(ans, cal(nums, i + 1, n, s));
        return dp[i][s % 3] = ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int sum = 0;
        return cal(nums, 0, n, sum);
    }
};