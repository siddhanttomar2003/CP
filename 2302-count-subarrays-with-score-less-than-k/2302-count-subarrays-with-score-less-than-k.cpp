typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans=0;
        ll i=0,j=0;
        ll curr=0;
        while(j<nums.size()){
         curr+=nums[j];
         while(curr*(j-i+1)>=k && i<=j){
            ans+=(j-i);
            curr-=nums[i];
            i++;
         }
         j++;
        }
        ll len=j-i;
        ans+=(len*(len+1))/2;
        return ans;
    }
};