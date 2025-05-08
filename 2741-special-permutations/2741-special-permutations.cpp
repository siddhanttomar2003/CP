class Solution {
public:
    int dp[15][1<<14];
    const int m=1e9+7;
    bool check(int last_ind,int i,vector<int>&nums){
        return last_ind==-1 || (nums[i]%nums[last_ind]==0)||(nums[last_ind]%nums[i]==0);
    }
    int cal(vector<int>&nums,int bitmask,int last,int fullmask, int n){
        if(bitmask==fullmask)return 1;
        if(dp[last+1][bitmask]!=-1)return dp[last+1][bitmask];
        int ans=0;
        for(int j=0;j<n;j++){
            if(!(bitmask&(1<<j)) && check(last,j,nums)){
                ans=(ans+cal(nums,bitmask|(1<<j),j,fullmask,n))%m;
            }
        }
        return dp[last+1][bitmask]=ans;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int fullmask=(1<<n)-1;
        return cal(nums,0,-1,fullmask,n);
    }
};