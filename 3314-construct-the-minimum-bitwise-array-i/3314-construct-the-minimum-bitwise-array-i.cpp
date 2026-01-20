class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            if(nums[i] & 1){
                int j = 0;
                int num = 0;
                for(j = 0; j < 32; j++){
                    if(nums[i] & (1 << j))continue;
                    else break;
                }
                j--;
                for(int k = 0; k < 32; k++){
                    if(k < j)num |= (1 << k);
                    else if(k == j)continue;
                    else {
                        if(nums[i] & (1 << k))num |= (1 << k);
                    }
                }
                ans[i] = num;
            }
            else ans[i] = -1;
        }
        return ans;
    }
};