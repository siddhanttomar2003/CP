class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       int ans=INT_MIN;
        int i=0;
        int e=nums.size()-1;
        while(i<e){
           if(ans<nums[i]+nums[e])ans=nums[i]+nums[e];
           i++;e--;
        }
        return ans;
    }
};