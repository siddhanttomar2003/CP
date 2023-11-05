class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxi=INT_MIN;
       int sum=0;
       for(int i=0;i<nums.size();i++)
       {
         sum+=nums[i];
         if(sum>=0)maxi=max(maxi,sum);
         if(sum<0)sum=0;  
       }
       if(maxi==INT_MIN){
          int newmax=INT_MIN;
          for(int i=0;i<nums.size();i++){
              if(nums[i]>newmax)newmax=nums[i];
          }
          return newmax;
       }
       else return maxi;
    }
};