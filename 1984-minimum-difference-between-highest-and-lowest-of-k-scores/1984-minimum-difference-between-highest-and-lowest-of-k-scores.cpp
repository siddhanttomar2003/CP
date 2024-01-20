class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      if(k==1)return 0;
      int l=0;int r=k-1;
      int diff=INT_MAX;
      while(r<nums.size()){
          diff=min(diff,nums[r]-nums[l]);
          l++;r++;
      }
         
      
      return diff;
    }
};