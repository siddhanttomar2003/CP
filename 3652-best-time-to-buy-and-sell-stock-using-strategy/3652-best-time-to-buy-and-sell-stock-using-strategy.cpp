class Solution {
public:
    typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll>pre(n + 1, 0), cal(n + 1, 0);
        for(int i = 1; i <= n; i++){
            pre[i] += (ll)pre[i - 1] + (ll)prices[i - 1];
            cal[i] += (ll)cal[i - 1] + (ll)prices[i - 1] * (ll)strategy[i - 1];
        }
        ll ind = -1;
        ll max_del = 0;
        for(int i = 0; i <= n - k; i++){
            ll c2 = (ll)pre[i + k] - (ll)pre[i + (k / 2)];
            // cout << c2 << endl;
            ll temp = c2;
            ll old = (ll)cal[i + k] - (ll)cal[i];
            // cout << temp << " " << old << endl;
            ll del = (ll)temp - (ll)old;
            if(del > max_del){
                max_del = del;
                ind = i;
            }
        }
        // cout << pre[n] << endl;
        // cout << ind << endl;
        if(ind != -1){
            for(int i = ind; i < ind + k; i++){
                if(i < ind + (k / 2))strategy[i] = 0;
                else strategy[i] = 1;
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += (ll)prices[i] * (ll)strategy[i];
        }
        return ans;
    }
};