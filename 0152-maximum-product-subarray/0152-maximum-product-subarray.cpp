typedef int ll;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        ll pre=1;
        ll suff=1;
        ll maxi=-1e9;
        for(int i=0;i<n;i++){
            pre*=nums[i];
            suff*=nums[n-i-1];
            maxi=max({maxi,pre,suff});
            if(suff==0)suff=1;
            if(pre==0)pre=1;
        }
        return maxi;

    }
};