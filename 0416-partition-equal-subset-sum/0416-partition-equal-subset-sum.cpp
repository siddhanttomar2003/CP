class Solution {
public:
    bool recur(vector<int> &nums,int take,int nottake,int i,vector<vector<vector<int>>>&dp){
        if(i==nums.size()){
            if(take==nottake)return true;
            else return false;
        }
        if(dp[i][take][nottake]!=-1)return dp[i][take][nottake];
        take+=nums[i];
      bool ans1=  recur(nums,take,nottake,i+1,dp);
        take-=nums[i];
        nottake+=nums[i];
      bool ans2=   recur(nums,take,nottake,i+1,dp);
        nottake-=nums[i];
        return dp[i][take][nottake]= ans1||ans2;

    }
    bool canPartition(vector<int>& nums) {
        int take=0;
        int nottake=0;
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(sum&1)return false;
        
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(sum,vector<int>(sum,-1)));
       return recur(nums,take,nottake,0,dp);
    
    }
};