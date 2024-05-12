class Solution {
public:
    int find_max(vector<int> &energy,int k,vector<int> &dp,int i,int n){
        if(i>=n)return 0;
        if(i==n-1)return energy[n-1];
       if(dp[i]!=-1e8)return dp[i];
        int take=energy[i]+find_max(energy,k,dp,i+k,n);
        return dp[i]=take;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        vector<int>dp(n,-1e8);
        for(int i=0;i<n;i++){
            ans=max(ans,find_max(energy,k,dp,i,n));
            cout<<ans<<endl;
         }
        
        return ans;
    }
};