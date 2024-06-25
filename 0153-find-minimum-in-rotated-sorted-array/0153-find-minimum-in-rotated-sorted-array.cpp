class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int e = n - 1;
        int ans=INT_MAX;
        while (i <= e) {
            int mid = i + (e - i) / 2;
            if(nums[mid]>=nums[i] && nums[mid]<=nums[e]){
                ans=min(ans,nums[i]);
                break;
            }
            else if(nums[mid]>=nums[i]){
                ans=min(ans,nums[i]);
                i=mid+1;    
            }
            else {
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};