class Solution {
public:
     typedef long long ll;
     int dp[8][16385];
     int ans(vector<int>&nums, int &full_mask , int &curr_mask,int op){
        if(curr_mask==full_mask){
           return dp[op][curr_mask]=0;
        }
        if(dp[op][curr_mask]!=-1)return dp[op][curr_mask];
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(!(curr_mask&(1<<i))){
                curr_mask|=(1<<i);
                for(int j=0;j<nums.size();j++){
                    if(!(curr_mask&(1<<j))){
                        curr_mask|=(1<<j);
                        curr=max(curr,op*(__gcd(nums[i],nums[j]))+ans(nums,full_mask,curr_mask,op+1));
                        curr_mask^=(1<<j);
                    }
                }
                curr_mask^=(1<<i);
            }
        }
        return dp[op][curr_mask]=curr;
     }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        int size=n;
        memset(dp,-1,sizeof(dp));
        int full_mask=(ll)(1<<size) - 1;
        int curr_mask=0;
        return ans(nums,full_mask,curr_mask,1);
    }
};