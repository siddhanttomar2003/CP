class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 2;
        int ans = 2;
        int n = nums.size();
        for(int i = 2; i < n; i++){
            while( i < n && nums[i] == nums[i - 1] + nums[i - 2]){
                len++;i++;
            }
            ans = max(ans, len);
            len = 2;
        }
        return ans;
    }
};