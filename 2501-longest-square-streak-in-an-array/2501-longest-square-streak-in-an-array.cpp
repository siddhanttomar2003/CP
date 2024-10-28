class Solution {
public:
    int cal(vector<int>&dp, vector<int>&nums, int i, long long last){
        if(i==nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int t=0;int nt=0;
        if(last==-1 || last*last==nums[i]){
            t=1+cal(dp,nums,i+1,nums[i]);
        }
        nt=cal(dp,nums,i+1,last);
        return dp[i]=max(t,nt);
    }
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
         vector<int>dp(n,-1);
        int ans=  cal(dp,nums,0,-1*1ll);
        if(ans==1)return -1;
        return ans;
    }
};