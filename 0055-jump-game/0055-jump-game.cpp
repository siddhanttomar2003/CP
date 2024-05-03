class Solution {
public:
//    bool recur(vector<int> & nums,int i,vector<int> &dp){
//     if(i==nums.size()-1)return true;
//     if(i>nums.size()-1)return false;
//     bool ans=false;
//     if(dp[i]!=-1)return dp[i];
//     for(int j=1;j<=nums[i];j++){
//       ans  =ans || recur(nums,i+j,dp);
//     }
//     return dp[i]=ans;
//    }
    bool canJump(vector<int>& nums) {
        // first using memoization
        int n=nums.size();
        vector<int>dp(n,0);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                if(i+j<n){
                 dp[i]=dp[i]|dp[i+j];
                 if(dp[i])break;
                }
            }
        }
        return dp[0];

    }
};