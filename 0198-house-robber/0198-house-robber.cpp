class Solution {
public:
    int find_max(vector<int> &dp,vector<int>  &nums,int i){
        if(i==0)return nums[0];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+find_max(dp,nums,i-2);
        int nottake=find_max(dp,nums,i-1);
       return  dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return find_max(dp,nums,n-1);
    }
};