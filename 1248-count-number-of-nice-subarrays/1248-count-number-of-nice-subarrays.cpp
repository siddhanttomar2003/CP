class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // changing the given array into binary as given in hint
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)nums[i]=1;
            else nums[i]=0;
        }
        // using subarray with given sum k;
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefix_sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            prefix_sum+=nums[i];
            int rem=prefix_sum-k;
            count+=mp[rem];
            mp[prefix_sum]++;
        }
        return count;
    } 
};