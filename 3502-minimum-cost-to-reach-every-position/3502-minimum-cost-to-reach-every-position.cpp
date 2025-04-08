class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n=cost.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int mini=cost[i];
            for(int j=0;j<i;j++){
               mini=min(mini,cost[j]);
            }
            ans[i]=mini;
        }
        return ans;
    }
};