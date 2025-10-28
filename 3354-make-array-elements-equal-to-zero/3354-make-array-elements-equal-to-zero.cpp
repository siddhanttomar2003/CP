class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n + 1, 0);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int count = 0;
        int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] == 0){
                if(pre[i] == sum)count += 2;
                else if(abs(pre[i] - sum) == 1)count += 1;
            }
            sum += nums[i];
        }
        return count;
    }
};