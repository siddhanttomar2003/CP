class Solution {
public:
    int recursive(vector<int> &nums,int index,vector<int>&dp){
        if(index==0)return nums[0];
        if(index==1)return nums[1];
        int maxi=INT_MIN;
        if(dp[index]!=-1)return dp[index];
        for(int i=2;i<=index;i++){
                maxi=max(maxi,recursive(nums,index-i,dp)+nums[index]);       
        }
        dp[index]=maxi;
        return maxi;
        
    }
    int rob(vector<int>& nums) {
        int count=INT_MIN;
        int n=nums.size();
        if(n<2)return nums[0];
        for(int i=n-1;i>=n-2;i--){
            vector<int>dp(n+1,-1);
            count=max(count,recursive(nums,i,dp));
        }
        return count;
    }
};