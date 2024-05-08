class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int i=0;
       int j=0;
       int n=nums.size();
       int count=0;
       int ans=0;
       while(j<n){
        if(nums[j]==1){
            
            ans=max(ans,j-i-count+1);
            j++;
        }
        else if(nums[j]==0 && count<1){
            j++;
            count++;
        }
        else {
           while(count>0){
            if(nums[i]==0)count--;
            i++;
           }
        }

       }
      if(ans==n)return ans-1;
      return ans;
    }
};