class Solution {
public:
    int minMoves(vector<int>& nums) {
       int sum=0;
       int min_element=INT_MAX;
       for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           if(nums[i]<min_element)min_element=nums[i];
       }
       return sum-min_element*(nums.size());
    }
};