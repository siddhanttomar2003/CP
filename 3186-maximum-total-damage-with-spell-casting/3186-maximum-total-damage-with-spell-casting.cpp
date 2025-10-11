class Solution {
public:
    typedef long long ll;
    ll dp[100001];
    ll cal(vector<ll> &arr, map<ll, ll> &val, int i){
        if(i == arr.size())return 0;
        if(dp[i] != -1)return dp[i];
        ll curr = 0;
        int idx = upper_bound(arr.begin(), arr.end(), arr[i] + 2) - arr.begin();
        if(idx != arr.size()){
            curr = val[arr[i]] * arr[i] + cal(arr, val, idx);
        }
        else curr = val[arr[i]] * arr[i];
        curr = max(curr, cal(arr, val, i + 1));
        return dp[i] = curr;
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<ll, ll>val;
        for(auto it : power)val[it]++;
        vector<ll>arr;
        for(auto it : val)arr.push_back(it.first);
        memset(dp, -1, sizeof(dp));
        return cal(arr, val, 0);
    }
};