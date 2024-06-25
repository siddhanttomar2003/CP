class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int e=n-1;
        while(i<=e){
            int mid=i+(e-i)/2;
            if(i==e)return nums[i];
            if(nums[mid]==nums[mid-1]){
                if((mid-i)&1){
                    i=mid+1;
                }
                else {
                    e=mid-2;
                }
            }
            else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else {
                if((e-mid)&1)e=mid-1;
                else i=mid+2;
            }   
            }
            return -1;
        
    }
};