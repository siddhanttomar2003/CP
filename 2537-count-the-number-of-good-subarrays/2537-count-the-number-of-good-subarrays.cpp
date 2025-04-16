typedef long long ll;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
         ll ans=0;
         int i=0,j=0;
         int n=nums.size();
         ll curr=0;
         map<ll,ll>mp;
         while(j<n){
            ll old=mp[nums[j]];
            curr-=(old*(old-1))/2;
            // cout<<nums[j]<<" "<<mp[nums[j]]<<" "<<curr<<endl;
            mp[nums[j]]++;
            ll neww=mp[nums[j]];
            curr+=(neww*(neww-1))/2;
            // cout<<nums[j]<<" "<<mp[nums[j]]<<" "<<curr<<" "<<ans<<endl;
            while(curr>=k && i<j){
                ans+=(n-j);
                ll o=mp[nums[i]];
                curr-=(o*(o-1))/2;
                mp[nums[i]]--;
                ll nee=mp[nums[i]];
                curr+=(nee*(nee-1))/2;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            j++;
         }
         return ans;
    }
};