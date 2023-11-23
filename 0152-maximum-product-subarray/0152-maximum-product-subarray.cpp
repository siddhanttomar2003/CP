class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
             prefix*=nums[i];
           
          suffix*=nums[nums.size()-i-1];
          ans=max(ans,max(prefix,suffix));
           if(nums[i]==0){prefix=1;
            }
            if(nums[nums.size()-i-1]==0){suffix=1;}
         
        
        }
        return ans;
    }
};