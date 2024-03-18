class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        int i=1;int e=n-2;
        while(i<=e){
            int mid=i+(e-i)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])return nums[mid];
            else if(nums[mid]==nums[mid-1]){
                if(mid&1)i=mid+1;
                else e=mid-1;
            }
            else{
                if(mid&1)e=mid-1;
                else i=mid+1;
            }
        }
        return 0;
    }
};