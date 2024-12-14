class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        long long ans=0;
        map<int,int>mp;
        while(j<n){
             mp[nums[j]]++;
             int mini=mp.begin()->first;
             int maxi=mp.rbegin()->first;
             if(maxi-mini<=2){
                j++;
             }
             else {
                while(mp.rbegin()->first-mp.begin()->first>2){
                    long long t=j-i;
                    ans+=t;
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)mp.erase(nums[i]);
                    i++;
                }
                j++;
             }
        }
        long long t=n-i;

        ans+=(t*(t+1))/2;
        return ans;
    }
};