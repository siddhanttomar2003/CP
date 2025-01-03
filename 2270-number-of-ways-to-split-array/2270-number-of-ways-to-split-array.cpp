class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>suff(n);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]+=(suff[i+1]+nums[i]*1ll);
        }
        long long  curr=0,ans=0;
        for(int i=0;i<n-1;i++){
            curr+=nums[i]*1ll;
            if(curr>=suff[i+1])ans++;
        }
        return ans;
    }
};