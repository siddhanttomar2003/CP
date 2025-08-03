class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int i = 1;
        while(i < n &&  nums[i] > nums[i - 1]){
            i++;
            count1++;
        }
        if(count1 == 0)return false;
        count1 = 0;
        while(i < n && nums[i] < nums[i - 1]){
            i++;
            count1++;
        }
        if(count1 == 0)return false;
        count1 = 0;
        while(i < n && nums[i] > nums[i - 1]){
            i++;
            count1++;
        }
        if(count1 == 0)return false;
        return i == n;
    }
};