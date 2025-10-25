class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int len = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            unordered_set<int>odd, even;
            for(int j = i; j < n; j++){
                if(nums[j] & 1)odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size() == even.size())len = max(len, j - i + 1);
            }
        }
        return len;
    }
};