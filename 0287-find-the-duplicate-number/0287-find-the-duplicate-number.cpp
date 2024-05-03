class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                if(nums[nums[i]-1]==nums[i])continue;
                else {
                    swap(nums[nums[i]-1],nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return nums[i];
        }
        return 0;

    }
};