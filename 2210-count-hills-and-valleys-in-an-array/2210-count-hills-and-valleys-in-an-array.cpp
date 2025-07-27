class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int last = nums[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] == last || i + 1 < n && nums[i] == nums[i + 1])continue;
            if(nums[i] > last && i + 1 < n && nums[i] > nums[i + 1])ans++;
            if(nums[i] < last  && i + 1 < n && nums[i] < nums[i + 1])ans++;
            last = nums[i];
        }
        return ans;
    }
};