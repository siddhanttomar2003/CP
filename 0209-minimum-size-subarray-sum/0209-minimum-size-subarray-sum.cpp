class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int len=INT_MAX;
        int curr=nums[j];
        while(j<nums.size()){
          if(curr<target){
            j++;
            if(j<nums.size())
            curr+=nums[j];
          }
          else{
            len=min(len,j-i+1);
            curr-=nums[i];i++;
          }

        }
        if(len==INT_MAX)len=0;
        return len;

    }
};