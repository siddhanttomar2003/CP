class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    ll mod_inv(ll a, ll b){
        ll res = 1;
        while(b){
            if(b & 1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll>curr;
        for(ll i  = 0; i < 32; i++){
            if(n & (1LL << i)){
                curr.push_back(1LL << i);
            }
        }
        ll pre = 1;
        int size = curr.size();
        int m = queries.size();
        vector<int>ans(m);
        vector<ll>prefix(size + 1, 1);
        for(int i = 0; i < size; i++){
            pre = (pre * curr[i]) % mod;
            // cout << pre << " ";
            prefix[i + 1] = pre;
        }
        // for(int i = 0; i < size; i++)cout << curr[i] << " ";
        // cout << endl;
        // for(int i = 0; i <= size; i++)cout << prefix[i] << " ";
        for(int i = 0; i < m; i++){
            int s = queries[i][0];
            int e = queries[i][1];
            ans[i] = (prefix[e + 1] * mod_inv(prefix[s], mod -2)) % mod;
        }
        return ans;
    }
};