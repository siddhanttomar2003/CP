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
        if(nums.size()==1)return true;
        int n=nums.size();
        int curr=0;
        int req=1;
        for(int i=n-2;i>=0;i--){
           curr=nums[i];
           if(curr>=req){
            req=1;
            continue;
           }
           else req++;
        }
        if(curr>=req)return true;
        else return false;
        

    }
};