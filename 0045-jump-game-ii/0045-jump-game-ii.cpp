class Solution {
public:
     int recur(vector<int> &nums, int i,vector<int> &dp){
        if(i>=nums.size()-1){
          return 0;
        }
        if((dp[i]!=1e8))return dp[i];
        for(int j=1;j<=nums[i];j++){
            dp[i]= min(dp[i] ,1+recur(nums,i+j,dp));
        }
       return  dp[i];

     }
    int jump(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>dp(n,1e8);
       return recur(nums,i,dp);
        
    }
};