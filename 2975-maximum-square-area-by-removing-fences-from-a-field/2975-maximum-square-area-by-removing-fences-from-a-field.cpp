class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int>st_r;
        hFences.push_back(m);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        for(int i = 0; i < hFences.size(); i++){
            for(int j = i + 1; j < hFences.size(); j++){
                st_r.insert(hFences[j] - hFences[i]);
            }
        }
        for(int i = 0; i < hFences.size(); i++){
            st_r.insert(hFences[i] - 1);
        }
        st_r.insert(m - 1);
        ll ans = -1;
        for(int i = 0; i < vFences.size(); i++){
            for(int j = i + 1; j < vFences.size(); j++){
                // st_c.insert(vFences[j] - vFences[i]);
                ll val = vFences[j] - vFences[i];
                if(st_r.find(val) != st_r.end())ans = max(ans, val * val);
            }
        }
        for(int i = 0; i < vFences.size(); i++){
            // st_c.insert(vFences[i] - 1);
            ll val = vFences[i] - 1;
            if(st_r.find(val) != st_r.end())ans = max(ans, val * val);
        }
        // st_c.insert(n - 1);
        ll val = n - 1;
        if(st_r.find(n - 1) != st_r.end())ans = max(ans, val * val);
        return ans % mod;
    }
};