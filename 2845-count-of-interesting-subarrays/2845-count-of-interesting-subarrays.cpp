typedef long long ll;
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if((nums[i]%modulo)==k)nums[i]=1;
            else nums[i]=0;
        }
        map<ll,ll>mp;
        mp[0]=1;
        ll sum=0;
        ll ans=0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
          if(sum<k){
            mp[sum]++;
            continue;
          }
          ans+=mp[(sum-k)%modulo];
          mp[sum%modulo]++;
        }
        return ans;
    }

};