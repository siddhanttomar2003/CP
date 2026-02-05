class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n, 0);
        for(int i = 0; i < n; i++){
            int idx = 0;
            if(nums[i] > 0){
                idx = (nums[i] + i) % n;
            }
            else idx = (i - abs(nums[i]) + n) % n;
            result[i] = nums[idx];
        }
        return result;
    }
};