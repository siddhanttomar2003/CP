class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // WITH BRUTE
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
         profit=max(profit,prices[i]-mini);
         mini=min(mini,prices[i]);
        }
        return profit;
    }
};