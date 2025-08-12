class Solution {
public:
    typedef long long ll;
    ll dp[301][301];
    const ll m = 1e9 + 7;
    int cal(vector<ll>&temp, int i, int sz, int curr){
        if(i == sz && curr == 0)return 1;
        if(i == sz)return 0;
        if(dp[i][curr] != -1)return dp[i][curr];
        ll ways = 0;
        if(temp[i] <= curr)
        ways = (ways + cal(temp, i + 1, sz, curr - temp[i])) % m;
        ways = (ways + cal(temp, i + 1, sz, curr)) % m;
        return dp[i][curr] = ways;
    }
    int numberOfWays(int n, int x) {
        vector<ll>temp;
        ll a = 1;
        while(pow(a, x) <= n){
            temp.push_back((ll)(pow(a, x)));
            a++;
        }
        // for(int i = 0; i < temp.size(); i++)cout << temp[i] << " ";
        memset(dp, -1, sizeof(dp));
        ll sz = temp.size();
        return cal(temp, 0, sz, n);
    }
};