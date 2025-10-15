class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n + 1, 0), suff(n + 1, 0);
        for(int i = 1; i < n; i++){
            pre[i] = nums[i] > nums[i - 1] ? 1 + pre[i - 1] : 0;
        }
        for(int i = n - 2; i >= 0; i--){
            suff[i] = nums[i + 1] > nums[i] ? 1 + suff[i + 1] : 0;
        }
        int maxi = 0;
        for(int i = 1; i < n - 1; i++){
            int mini = min(pre[i], suff[i + 1]);
            maxi = max(maxi, mini);
        }
        return maxi + 1;
    }
};