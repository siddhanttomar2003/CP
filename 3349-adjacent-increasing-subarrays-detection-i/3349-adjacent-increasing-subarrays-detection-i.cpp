class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1)return true;
        vector<int>pre(n + 1, 0), suff(n + 1, 0);
        int count = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                count++;
            }
            else {
                count = 0;
            }
            pre[i] = count;
        }
        count = 0;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1])count++;
            else count = 0;
            suff[i] = count;
        }
        for(int i = 1; i < n - 1; i++)cout << pre[i] << " " << suff[i] << " " << endl;
        for(int i = 1; i < n - 1; i++){
            if(pre[i] >= k - 1 && suff[i + 1] >= k - 1)return true;
        }
        return false;
    }
};