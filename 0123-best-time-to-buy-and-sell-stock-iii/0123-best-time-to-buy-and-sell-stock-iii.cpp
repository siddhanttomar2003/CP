class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int first_profit=0;
       int first=INT_MAX;
       int second=INT_MIN;
       int left=INT_MIN;
       for(int i=0;i<prices.size();i++){
        first=min(first,prices[i]);
        first_profit=max(first_profit,prices[i]-first);
        left=max(left,first_profit-prices[i]);
        second=max(second,left+prices[i]);
       }
       return second;

    }
};