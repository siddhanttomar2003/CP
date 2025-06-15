typedef long long ll;
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        vector<ll>pre_max(n),pre_min(n);
        ll aage=m-1;
        pre_max[n-1]=nums[n-1];
        ll maxi=pre_max[n-1];
        pre_min[n-1]=nums[n-1];
        ll mini=pre_min[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            if(nums[i]<mini){
                mini=nums[i];
            }
            pre_max[i]=maxi;
            pre_min[i]=mini;
        }
        ll ans=-1e12;
        for(int i=0;i<n;i++){
            if(i+aage<n){
                ll op1=(ll)nums[i]*(pre_max[i+aage]);
                ll op2=(ll)nums[i]*(pre_min[i+aage]);
                ans=max({ans,op1,op2});
            }
        }
        return ans;

    }
};