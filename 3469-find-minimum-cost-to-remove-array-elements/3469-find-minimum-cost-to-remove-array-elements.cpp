typedef long long ll;
class Solution {
public:
    ll dp[1001];
    ll cal(vector<int>&nums, int i, int last){
        if(i>=nums.size())return nums[last];
        if(dp[last]!=-1)return dp[last];
        ll mini=1e10;
         if(i+1>=nums.size()){
            return dp[last]=max(nums[i],nums[last]);
        }
        else {
            mini=min(mini,max(nums[last],nums[i])+cal(nums,i+2,i+1));
            mini=min(mini,max(nums[last],nums[i+1])+cal(nums,i+2,i));
            mini=min(mini,max(nums[i],nums[i+1])+cal(nums,i+2,last));
        }
        return dp[last]=mini;
    }
    int minCost(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2){
            return max(nums[0],nums[1]);
        }
        memset(dp,-1,sizeof(dp));
        return min({max(nums[1],nums[2])+cal(nums,3,0),max(nums[0],nums[2])+cal(nums,3,1),max(nums[0],nums[1])+cal(nums,3,2)});
    }
};