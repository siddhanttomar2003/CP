class Solution {
public:
    typedef long long ll;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<ll,ll>mp;
        set<ll>st;
        for(ll i = 0; i < n; i++)st.insert(i);
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>pq;
        sort(meetings.begin(), meetings.end());
        ll start = meetings[0][0];
        ll end = meetings[0][1];
        pq.push({end, 0, start});
        mp[0]++;
        st.erase(0);
        cout << 0 << endl;
        ll size = meetings.size();
        for(ll i = 1; i < size; i++){
            ll curr_start = meetings[i][0];
            ll curr_dur = meetings[i][1] - meetings[i][0];
            while(!pq.empty() && pq.top()[0] <= curr_start){
                ll idx = pq.top()[1];
                st.insert(idx);
                pq.pop();
            }
            if(st.size() == 0){
                ll idx  = pq.top()[1];
                st.insert(idx);
                curr_start = max(curr_start, pq.top()[0]);
                pq.pop();
            }
            auto it = st.begin();
            ll idx = *it;
            // cout << idx << endl;
            st.erase(idx);
            mp[idx] ++;
            pq.push({curr_dur + curr_start, idx, curr_start});
        }
        ll maxi = -1;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }
        for(auto it : mp){
            if(it.second == maxi)return it.first;
        }
        return -1;
    }
};