class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int e=n-1;
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        while(i<=e){
    int mid=i+(e-i)/2;
    if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;
    else if(nums[mid]>nums[mid-1]){
        // peak exist aage
        i=mid;
    }
    else e=mid;
        }
        return -1;
    }
};