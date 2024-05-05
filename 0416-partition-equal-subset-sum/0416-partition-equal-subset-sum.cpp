class Solution {
public:
    // bool recur(vector<int> &nums,vector<vector<int>> &dp, int sum, int i, int take){
    //     if(i==nums.size()){
    //         if(take==sum/2){
    //             return true;
    //         }
    //         return false;
    //     }
    //     if(take==sum/2){
    //      return   dp[i][take]=true;
    //     }
    //     if(dp[i][take]!=-1)return dp[i][take];
    //      take+=nums[i];
    //    bool ans1=  recur(nums,dp,sum,i+1,take);
    //      take-=nums[i];
    //      bool ans2=recur(nums,dp,sum,i+1,take);
    //     return   dp[i][take]=ans1 || ans2;
    // }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(sum&1)return false;
        // if sum is even there must be some method to divide the array into 
        // two parts having equal sum
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int> (sum+1,0));
         for(int i=0;i<n;i++){
         dp[i][0]=1;
         }
         dp[0][nums[0]]=1;
         for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool take=false;
                if(nums[i]<=j)take=dp[i-1][j-nums[i]];
                bool nottake=false;
               nottake=dp[i-1][j];
               dp[i][j]=take|nottake;
            }

         }
         return dp[n-1][sum];
         

    }
};