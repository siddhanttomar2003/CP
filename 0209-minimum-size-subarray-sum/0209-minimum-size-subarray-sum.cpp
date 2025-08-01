class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 1e9;
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        while(j < n){
            sum += nums[j];
            while(sum >= target && i <= j){
                len = min(len, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(len == 1e9)return 0;
        return len;
    }
};