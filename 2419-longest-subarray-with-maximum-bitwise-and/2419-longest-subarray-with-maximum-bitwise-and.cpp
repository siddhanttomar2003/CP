class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int len = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxi)len++;
            else len = 0;
            ans = max(ans, len);
        }
        return ans;
    }
};