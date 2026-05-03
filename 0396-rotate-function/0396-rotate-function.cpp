class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int tot = 0;
        for(int i = 0; i < n; i++){
            tot += (i * nums[i]);
        }
        int maxi = tot;
        for(int i = 0; i < n - 1; i++){
            tot = tot + sum - ((n) * nums[n - i - 1]);
            maxi = max(maxi, tot);
        }
        return maxi;
    }
};