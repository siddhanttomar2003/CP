class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int temp=money;
        int smallest=INT_MAX;
        int second_smallest=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<=smallest){
                second_smallest=smallest;
                smallest=prices[i];
            }
            else if(prices[i]<second_smallest&&prices[i]>smallest){
                second_smallest=prices[i];
            }
        }
        if(smallest+second_smallest>money)return money;
        else return money-(smallest+second_smallest);

      
    }
};