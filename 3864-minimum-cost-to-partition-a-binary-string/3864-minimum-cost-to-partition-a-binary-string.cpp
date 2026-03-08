class Solution {
public:
    typedef long long ll;
    map<pair<int,int>, ll> memo;

    ll cal(int i, int len, vector<ll>& pre, int e, int f) {
        if (len == 0) return 0;
        auto key = make_pair(i, len);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        ll sum = pre[i + len - 1] - pre[i - 1];
        ll direct = (sum == 0) ? f : (ll)len * sum * e;
        ll mini = direct;
        if (len % 2 == 0) {
            int half = len / 2;
            ll left  = cal(i, half, pre, e, f);
            ll right = cal(i + half, half, pre, e, f);
            mini = min(mini, left + right);
        }

        return memo[key] = mini;
    }

    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        string l = s;   
        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + (s[i] - '0');
        return cal(1, n, pre, encCost, flatCost);
    }
};