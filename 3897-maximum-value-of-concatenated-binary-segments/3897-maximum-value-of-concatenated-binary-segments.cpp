class Solution {
public:
    typedef long long ll;
    const int m = 1e9 + 7;
    ll cal(ll a, ll b){
        ll res = 1;
        while(b){
            if(b & 1)res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int, int>>v;
        int n = nums1.size();
        ll sum = -1;
        int pre = 0;
        for(int i = 0; i < n; i++){
            if(nums0[i] == 0)pre += nums1[i];
            else{ 
                v.push_back({nums1[i], nums0[i]});
                sum += nums1[i] + nums0[i];
            }
        }
        sort(v.begin(), v.end(), [](pair<int, int>&a, pair<int, int>&b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        // for(auto it : v)cout << it.first << " " << it.second << endl;
        ll ans = 0;
        while(pre > 0){
            ans = (ans + cal(2 * 1ll , pre + sum)) % m;
            pre--;
        }
        for(int i = 0; i < v.size(); i++){
            int freq = v[i].first;
            for(int j = 0; j < freq; j++){
                ans = (ans + cal(2 * 1ll, sum)) % m;
                sum--;
            }
            sum -= v[i].second;
        }
        return ans;
    }

};