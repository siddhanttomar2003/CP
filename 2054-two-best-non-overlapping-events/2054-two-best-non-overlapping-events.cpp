class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int>suff_max(n + 1, 0);
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            suff_max[i] = max(suff_max[i + 1], events[i][2]);
        }
        vector<int>temp;
        for(int i = 0; i < n; i++)temp.push_back(events[i][0]);
        for(int i = 0; i < n; i++){
            int curr = events[i][2];
            int idx = upper_bound(temp.begin(), temp.end(), events[i][1]) - temp.begin();
            ans = max(ans, curr + suff_max[idx]);
        }
        return ans;
    }
};