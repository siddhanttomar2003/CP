class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        int e=nums.size()-1;
        int mid;
        while(i<=e){
            mid=i+(e-i)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)i=mid+1;
            else e=mid-1;   
        }
        if(nums[mid]>target)return mid;
        else return mid+1;
    }
};