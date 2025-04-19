typedef long long ll;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            ll n1=((ll)lower-(ll)(nums[i]));
            ll n2=((ll)upper-(ll)(nums[i]));
            ll ind1=lower_bound(nums.begin(),nums.end(),n1)-nums.begin();
            ll ind2=upper_bound(nums.begin(),nums.end(),n2)-nums.begin();
            if(ind2<=ind1)continue;
            ans+=(ind2-ind1);
            if(i>=ind1 && ind2-1>=i)ans--;
        }
        return ans/(2*1ll);
    }
};