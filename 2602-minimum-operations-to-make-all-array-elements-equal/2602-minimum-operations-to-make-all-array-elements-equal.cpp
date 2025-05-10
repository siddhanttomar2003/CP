typedef long long ll;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        int n=nums.size();
        vector<long long>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]+=(pre[i-1]+(ll)copy[i-1]);
        }
        vector<long long>f;
        for(auto it:queries){
            int ind=lower_bound(copy.begin(),copy.end(),it)-copy.begin();
            ll smaller=pre[ind];
            ll req= it*1ll*ind;
            ll ans=0;
            ans+=(req-smaller);
            ll larger=pre[n]-pre[ind];
            req=(n-ind)*1ll*(it);
            ans+=(larger-req);
            f.push_back(ans);
        }
        return f;
    }
};