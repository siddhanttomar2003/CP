class Solution {
public:
    int cal(vector<int>&nums, int tar, unordered_map<int,unordered_map<int,int>>&dp, int i, int curr){
     if(i==nums.size()){
        return curr==tar;
     }
     if(dp[i].count(curr))return dp[i][curr];
     int ways=0;
     ways+=cal(nums,tar,dp,i+1,curr+nums[i]);
     ways+=cal(nums,tar,dp,i+1,curr-nums[i]);
     return dp[i][curr]=ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>>dp;
        return cal(nums,target,dp,0,0);
    }
};