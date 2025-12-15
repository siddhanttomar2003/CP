class Solution {
public:
    typedef long long ll;
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            ll count = 1;
            while(i + 1 < n && prices[i + 1] - prices[i] == -1){
                count++;
                i++;
            }
            ans += (count * (count + 1)) / 2;
        }
        return ans;
    }
};