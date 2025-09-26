class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                int sum = nums[i] + nums[j];
                int ind = lower_bound(nums.begin(), nums.end(), sum) - nums.begin();
                if(ind > j)count += (ind - j - 1);
            }
        }
        return count;
    }
};