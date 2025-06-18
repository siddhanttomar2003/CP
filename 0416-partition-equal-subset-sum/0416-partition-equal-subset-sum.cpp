class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        int tar=sum/2;
        int n=nums.size();
        vector<int>dp(tar+1,0);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=tar;j>0;j--){
                if(nums[i]<=j){
                    dp[j]|=dp[j-nums[i]];
                }
            }
        }
        return dp[tar];
    }
};