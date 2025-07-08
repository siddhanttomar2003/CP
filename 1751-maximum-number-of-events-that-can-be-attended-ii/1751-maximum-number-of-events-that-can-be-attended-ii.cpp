class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());  // Sort by start time
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<int> start_times(n);
        for (int i = 0; i < n; i++) {
            start_times[i] = events[i][0];
        }

        for (int i = n - 1; i >= 0; i--) {
            int next = upper_bound(start_times.begin(), start_times.end(), events[i][1]) - start_times.begin();
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(
                    dp[i + 1][j],                      
                    events[i][2] + dp[next][j - 1]     
                );
            }
        }

        return dp[0][k];
    }
};
