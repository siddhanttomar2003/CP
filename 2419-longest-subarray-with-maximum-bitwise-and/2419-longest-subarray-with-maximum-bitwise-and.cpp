class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int len=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
         if(nums[i]==maxi){
            int count=0;
            while( i<n && nums[i]==maxi){
               count++;i++;
            }
            len=max(len,count);
         }
        }
        return len;
    }
};