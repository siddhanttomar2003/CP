class Solution {
public:
    int subarrays(vector<int> &nums,int k){
        int count=0;
        int i=0;int j=0;
        unordered_map<int,int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp.size()<=k)j++;
            else{
            
              while(mp.size()>k){
                count+=j-i;
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
              }
              j++;
            }
        }
        int n=j-i;
        count+=(n*(n+1))/2;
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int c1=subarrays(nums,k);
        int c2=subarrays(nums,k-1);
        return c1-c2;
    }
};