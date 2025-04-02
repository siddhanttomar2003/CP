typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<ll>suff_max(n,0);
        ll maxi=-1;
        suff_max[n-1]=-1;
        for(int i=n-2;i>=0;i--){
           maxi=max(maxi,(ll)nums[i+1]);
           suff_max[i]=maxi;
        }
        ll ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                 ans=max(ans,(nums[i]-nums[j])*1ll*(suff_max[j]));
            }
        }
        return ans;
    }
};