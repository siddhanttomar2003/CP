class Solution {
public:
    typedef long long ll;
    long long countStableSubarrays(vector<int>& c) {
        ll ans = 0;
        int n = c.size();
        vector<ll>pre(n + 1, 0);
        for(int i = 1; i <= n; i++)pre[i] = pre[i - 1] + c[i - 1];
        map<int, vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[c[i]].push_back(i);
        }
        for(auto it : mp){
            vector<int> & temp = it.second;
            map<int, vector<int>>mp2;
            for(int i = 0; i < temp.size(); i++){
                ll sum = pre[temp[i] + 1];
                if(mp2.find(sum - 2 * it.first) != mp2.end()){
                    if(mp2[sum - 2 * it.first].back() < temp[i] - 1)ans += mp2[sum - 2 * it.first].size();
                    else ans += mp2[sum - 2 * it.first].size() - 1;
                }
                mp2[sum].push_back(temp[i]);
            }
        }
        return ans;
    }
};