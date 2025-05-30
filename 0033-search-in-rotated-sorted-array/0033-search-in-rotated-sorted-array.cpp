class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int e=nums.size()-1;
        while(i<=e){
            int mid=i+(e-i)/2;
            if(nums[mid]==target)return mid;
           else  if(nums[mid]>=nums[i]){
                if(target>=nums[i]&&target<=nums[mid]){
                    e=mid-1;
                }
                else i=mid+1;
            }
            else{
                if(target>=nums[mid]&&target<=nums[e])i=mid+1;
                else e=mid-1;
            }
        }
        return -1;
    }
};