class Solution {
public:
    int cal(vector<int>&nums, int i, int last, map<int,map<int,int>>&dp){
        if(i>=nums.size())return nums[last];
        if( dp.find(i)!=dp.end() && dp[i].find(last)!=dp[i].end())return dp[i][last];
        int mini=1e9;
        if(last==-1){
         mini=min(mini,max(nums[i],nums[i+1])+cal(nums,i+3,i+2,dp));
         mini=min(mini,max(nums[i],nums[i+2])+cal(nums,i+3,i+1,dp));
         mini=min(mini,max(nums[i+1],nums[i+2])+cal(nums,i+3,i,dp));
        }
        else if(i+1>=nums.size()){
            return dp[i][last]=max(nums[i],nums[last]);
        }
        else {
            mini=min(mini,max(nums[last],nums[i])+cal(nums,i+2,i+1,dp));
            mini=min(mini,max(nums[last],nums[i+1])+cal(nums,i+2,i,dp));
            mini=min(mini,max(nums[i],nums[i+1])+cal(nums,i+2,last,dp));
        }
        return dp[i][last]=mini;
    }
    int minCost(vector<int>& nums) {
        map<int,map<int,int>>dp;
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2){
            return max(nums[0],nums[1]);
        }
        return cal(nums,0,-1,dp);
    }
};