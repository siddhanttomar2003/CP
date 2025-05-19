const int mod = 1e9 + 7;
typedef long long ll;
typedef vector<ll> vl;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vl, vector<vl>, greater<vl>> pq_sell;
        priority_queue<vl> pq_buy;
        for (auto it : orders) {
            if (it[2] == 1) {
                ll curr=it[1];
                while (pq_buy.size() > 0 && pq_buy.top()[0] >= it[0] && curr>0) {
                    ll price=pq_buy.top()[0];
                    ll num1 =  pq_buy.top()[1] ;
                    ll num2 = curr;
                    ll mini = min(num1, num2);
                    num2 -= mini;
                    num1-= mini;
                    pq_buy.pop();
                    if (num1 > 0){
                        pq_buy.push({price,num1});
                    }
                    curr=num2;
                } 
                if(curr>0)pq_sell.push({it[0],curr});

            } else {
                ll curr=it[1];
                while (pq_sell.size() > 0 && pq_sell.top()[0] <= it[0] && curr>0) {
                    ll price=pq_sell.top()[0];
                    ll num1 =  pq_sell.top()[1] ;
                    ll num2 = curr;
                    ll mini = min(num1, num2);
                    num2 -= mini;
                    num1-= mini;
                    pq_sell.pop();
                    if (num1 > 0){
                        pq_sell.push({price,num1});
                    }
                    curr=num2;
                } 
                if(curr>0){
                    pq_buy.push({it[0], curr});
                }
            }
        }
        int amount = 0;
        while (!pq_sell.empty()) {
            amount = ((ll)amount + (ll)pq_sell.top()[1]) % mod;
            pq_sell.pop();
        }
        while (!pq_buy.empty()) {
            amount = ((ll)amount + (ll)pq_buy.top()[1]) % mod;
            pq_buy.pop();
        }
        return amount;
    }
};