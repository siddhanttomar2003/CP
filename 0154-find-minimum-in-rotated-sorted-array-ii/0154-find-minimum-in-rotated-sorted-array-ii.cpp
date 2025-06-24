class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == nums[i] && nums[mid] == nums[j]){
                mini = min(mini, nums[i]);
                i++;
                j--;
            }
            else if(nums[mid] >= nums[i]){
                mini = min(mini, nums[i]);
                i = mid + 1;
            }
            else {
                mini = min(mini, nums[mid]);
                j = mid - 1;
            }
        }
        return mini;
    }
};