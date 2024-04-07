class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)return abs(k-nums[0]);
       long long  ans=0;
        
            int mid=n/2;
            if(nums[mid]<k){
                // check right
                for(int i=mid;i<n;i++){
                    if(nums[i]<k)ans+=abs(nums[i]-k);
                    else break;
                }
            }
            else if(nums[mid]>k){
                for(int i=mid;i>=0;i--){
                    if(nums[i]>k)ans+=abs(nums[i]-k);
                    else break;
                }
            } 
        
        return ans;
      
    }
};