typedef long long ll;
class Solution {
public:
    ll dp[1001];
    int cal(vector<vector<int>>&pre, int i, int k , int n){
        if(i == n)return 0;
        if(dp[i] != -1)return dp[i];
        int cost = 2e9;
        for(int j=i;j<n;j++){
            cost = min(cost , pre[i][j]+k+cal(pre,j+1,k,n));
        }
        return dp[i]=cost;
    }
    int minCost(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        vector<vector<int>>pre(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int count=0;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp[nums[j]]==2)count+=2;
                else if(mp[nums[j]]>2)count++;
                pre[i][j] = count;
            }
        }
        return cal(pre,0,k,n);
    }
};