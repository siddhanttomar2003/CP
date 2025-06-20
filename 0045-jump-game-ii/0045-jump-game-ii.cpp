class Solution {
public:
    int dp[10001];
    int cal(vector<int>&nums, int i, int n){
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int steps=1e9;
        for(int j=1;j<=nums[i];j++){
            if(i+j<=n-1){
               steps=min(steps,1+cal(nums,i+j,n));
            }
        }
        return dp[i]=steps;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return cal(nums,0,n);
    }
};