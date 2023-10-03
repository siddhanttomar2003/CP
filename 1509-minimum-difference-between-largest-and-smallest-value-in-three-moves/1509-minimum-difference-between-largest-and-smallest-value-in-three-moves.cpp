class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4)
        {
            return 0;
        }

        sort(nums.begin(),nums.end());
        int ans1 = abs(nums[0]-nums[n-4]);
        int ans2 = abs(nums[3]-nums[n-1]);
        int ans3 = abs(nums[1]-nums[n-3]);
        int ans4 = abs(nums[2]-nums[n-2]);

        return min(min(ans1,ans2),min(ans3,ans4));
    }
};