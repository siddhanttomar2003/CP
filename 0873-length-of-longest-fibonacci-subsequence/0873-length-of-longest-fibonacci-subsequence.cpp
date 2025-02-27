class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]=i;
        }
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n - 2; i++) {
            int ele1 = arr[i];
            for (int j = i + 1; j < n - 1; j++) {
                int ele2 = arr[j];
                int num = ele1 + ele2;
                if (mp.find(num) != mp.end()) {
                    if (mp[num] > j) {
                        dp[mp[num]][j] = 1 + dp[j][i];
                        ans = max(ans, dp[mp[num]][j]);
                    }
                }
            }
        }
        if (ans > 0)
            return ans + 2;
        return 0;
    }
};