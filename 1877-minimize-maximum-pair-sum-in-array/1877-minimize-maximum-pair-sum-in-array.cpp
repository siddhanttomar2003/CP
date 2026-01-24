class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        int mini = 0;
        while(i < j){
            mini = max(mini, nums[i] + nums[j]);
            i++;j--;
        }
        return mini;
    }
};