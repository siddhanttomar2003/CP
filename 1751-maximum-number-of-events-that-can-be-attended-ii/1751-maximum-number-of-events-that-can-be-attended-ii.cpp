class Solution {
public:
    vector<vector<int>> dp;
    vector<int>ex;
    int cal(vector<vector<int>>& e, int i, int k, int n, vector<int> &ex) {
        if (i == n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int ans = cal(e, i + 1, k, n, ex);  
        if (k > 0) {
            int num = e[i][1];
            int ind = upper_bound(ex.begin(), ex.end(), num) - ex.begin();
            ans = max(ans, e[i][2] + cal(e, ind, k - 1, n, ex)); 
        }
        return dp[i][k] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        ex.assign(n, 0);
        sort(events.begin(), events.end());
        for(int i = 0; i < n; i++){
            ex[i] = events[i][0];
        }
        dp.assign(n, vector<int>(k + 1 , -1));
        return cal(events, 0, k, n, ex);
    }
};
