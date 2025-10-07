class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        map<int,int>mp;
        vector<int>ans(n, -1);
        set<int>st;
        for(int i = 0; i < n; i++){
            if(rains[i] == 0)st.insert(i);
            else {
                if(mp.find(rains[i]) == mp.end()){
                    mp[rains[i]] = i;
                }
                else {
                    int idx = mp[rains[i]];
                    mp[rains[i]] = i;
                    auto it = st.upper_bound(idx);
                    if(it != st.end()){
                        ans[*it] = rains[i];
                        st.erase(*it);
                    }
                    else return {};
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(rains[i] == 0 && ans[i] == -1)ans[i] = 1;
        }
        return ans;
    }
};