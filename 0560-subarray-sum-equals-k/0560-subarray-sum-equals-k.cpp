class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {   
        //using prefix sum as taught earlier
        int ans=0;int sum=0;
         unordered_map<int,int>mpp;
         mpp[sum]++;
        for(int i=0;i<nums.size();i++){
            
           sum+=nums[i];
           ans+=mpp[sum-k];
           mpp[sum]++;  
             
                     
            
        }
        return ans;
    }
};