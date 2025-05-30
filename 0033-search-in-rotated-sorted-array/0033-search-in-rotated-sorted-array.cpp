class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
           if(nums[mid]==target)return mid;
           else if(nums[mid]>=nums[low]){// left part sorted
               if(target>=nums[low] && target<=nums[mid]){
                 high=mid;
               }
               else {
                  low=mid+1;
               }
            }
            else {
                if(target>=nums[mid] && target<=nums[high]){
                    low=mid;
                }
                else {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};