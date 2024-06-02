class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        unordered_map<long long , long long>mp;
        int i=0;
        int j=0;
        long long sum=0;
        for( j=0;j<k;j++){
             sum+=nums[j];
             mp[nums[j]]++;
        }
        if(mp.size()==k)ans=max(ans,sum);
        while(j<n){
            mp[nums[i]]--;
            sum-=nums[i];
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            sum+=nums[j];
            mp[nums[j]]++;
            if(mp.size()==k)ans=max(ans,sum);
            j++;i++;
        }
          return ans;

    }
};