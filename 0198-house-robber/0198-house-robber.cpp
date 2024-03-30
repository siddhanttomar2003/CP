class Solution {
public:
    int recursive(vector<int> &nums,int i,vector<int> &dp){
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+recursive(nums,i-2,dp);
        int not_pick=recursive(nums,i-1,dp);
        dp[i]=max(pick,not_pick);
        return max(pick,not_pick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int i=nums.size()-1;
        return  recursive(nums,i,dp);
    }
};