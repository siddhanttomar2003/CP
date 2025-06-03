class Solution {
public:
    int func(vector<int>&nums, int k){
        map<int,int>mp;
        int i=0,j=0;
        int n=nums.size();
        int ans=0;
        while(j<n){
           mp[nums[j]]++;
           while(mp.size()>k){
              ans+=(j-i);
              mp[nums[i]]--;
              if(mp[nums[i]]==0)mp.erase(nums[i]);
              i++;
           }
           j++;
        }
        int len=j-i;
        ans+=(len*(len+1))/2;
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return func(nums,k) - func(nums,k-1);
    }
};