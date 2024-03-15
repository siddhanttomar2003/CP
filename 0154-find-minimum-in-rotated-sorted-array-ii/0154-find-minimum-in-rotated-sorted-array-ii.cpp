class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int e=nums.size()-1;
        int mini=INT_MAX;
        while(i<=e){
            int mid=i+(e-i)/2;
            if(nums[mid]==nums[i]&&nums[mid]==nums[e]){
                mini=min(mini,nums[mid]);
                i++;e--;
                continue;
            }
            if(nums[mid]>=nums[i]&&nums[mid]<=nums[e]){
                mini=min(mini,nums[i]);
                e=mid-1;
            }
            else if(nums[mid]>=nums[i]){
                //left side sorted
                mini=min(mini,nums[i]);
                i=mid+1;
            }
            else{
                //right side sorted including the middle one
                mini=min(mini,nums[mid]);
                e=mid-1;
            }

        }
        return mini;
    }
};