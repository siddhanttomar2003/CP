class Solution {
public:
    typedef long long ll;
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long sc) {
        int n = s.size();
        ll m = p.size();
        sort(p.begin(), p.end());
        vector<int>ans(n, 0);
        vector<double>temp(m);
        for(int i = 0; i < m; i++){
            temp[i] = ((double)p[i] * 1.00);
        }
        for(ll i = 0; i < n; i++){
            double req = (double)sc / (double)s[i];
            ll idx = lower_bound(temp.begin(), temp.end(), req) - temp.begin();
            ans[i] = m - idx;
        }
        return ans;
    }
};