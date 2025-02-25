class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        long long n=nums.size();
        map<int,long long>mp;
        for(int i=0;i<n;i++){
         mp[i-nums[i]]++;
        }
        for(auto it:mp){
            ans+=(it.second*(n-it.second));
        }
        return ans/(2*1ll);
    }
};