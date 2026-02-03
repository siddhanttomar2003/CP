class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i + 1 < n && nums[i + 1] > nums[i])i++;
        if(i == 0)return false;
        int last = i;
        while(i + 1 < n && nums[i + 1] < nums[i])i++;
        if(last == i)return false;
        last = i;
        while(i + 1 < n && nums[i + 1] > nums[i])i++;
        return i == n - 1 && last != i;
    }
};