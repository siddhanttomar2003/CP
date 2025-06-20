class Solution {
public:
    int dp[21][2001];
    int cal(vector<int>&nums, int tar, int i, int curr){
     if(i==nums.size()){
        return curr==tar;
     }
     if(dp[i][curr+1000]!=-1)return dp[i][curr+1000];
     int ways=0;
     if(curr+nums[i]<=1000){
     ways+=cal(nums,tar,i+1,curr+nums[i]);
     }
     if(curr-nums[i]>=-1000){
     ways+=cal(nums,tar,i+1,curr-nums[i]);
     }
     return dp[i][curr+1000]=ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return cal(nums,target,0,0);
    }
};