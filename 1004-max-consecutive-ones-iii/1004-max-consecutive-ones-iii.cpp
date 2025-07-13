class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int i = 0, j = 0;
        int n = nums.size();
        int curr = 0;
        while(j < n){
            if(nums[j] == 0)curr++;
            while(curr > k && i <= j){
                if(nums[i] == 0)curr--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};