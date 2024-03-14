class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        int prefix_sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
            ans+=mp[prefix_sum-goal];
            mp[prefix_sum]++;
        }
        return ans;
    }
};