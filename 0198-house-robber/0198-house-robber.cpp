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
        // now tabulating it
        // first write the base case
        // go in reverse direction as in memo
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=0;
            int nottake=0;
            if(i>1)take=nums[i]+dp[i-2];
            else take=nums[i];
            nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        if(n==2)return max(nums[0],nums[1]);
        return dp[n-1];
    }
};