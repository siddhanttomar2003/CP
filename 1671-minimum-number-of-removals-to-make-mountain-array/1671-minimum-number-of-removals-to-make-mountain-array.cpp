class Solution {
public:

    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
        }
        vector<int>tp(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j] && tp[i]<1+tp[j]){
                    tp[i]=1+tp[j];
                }
            }
        }
        int maxi=3;
        for(int i=1;i<n-1;i++){
            if(dp[i]>=2 && tp[i]>=2){
            maxi=max(maxi,dp[i]+tp[i]-1);
            }
        }
        for(int i=0;i<n;i++)cout<<dp[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)cout<<tp[i]<<" ";

        return n-maxi;

    }
};