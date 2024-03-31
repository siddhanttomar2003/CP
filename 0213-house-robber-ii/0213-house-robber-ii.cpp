class Solution {
public:
     int maxi2(vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n,0);
        dp[1]=nums[1];
        dp[0]=0;
        for(int i=2;i<n;i++){
            int pick=INT_MIN,not_pick=INT_MIN;
            pick=nums[i]+dp[i-2];
            not_pick=dp[i-1];
            dp[i]=max(pick,not_pick);
        }
        return dp[n-1];
     }
    int maxi1(vector<int> &nums){
    int i=0;
    int n=nums.size();
    vector<int> dp(n-1,0);
    dp[0]=nums[0];
    for(int i=1;i<n-1;i++){
    int pick=INT_MIN,not_pick=INT_MIN;
    if(i>1)pick=nums[i]+dp[i-2];
    not_pick=dp[i-1];
    dp[i]=max(pick,not_pick);
    }
    return dp[n-2];
    }
    int rob(vector<int>& nums) {
        // same as house robber just simple logic 
        // in this que we cannot take 1st and last element rest all are same
         if(nums.size()==1)return nums[0];
         if(nums.size()==2)return max(nums[0],nums[1]);
        int index=0;
        int ans1=maxi1(nums);
        int ans2=maxi2(nums);
        return max(ans1,ans2);
    }
};