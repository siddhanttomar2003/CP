class Solution {
public:
    const int m=1e9+7;
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> pre(n, vector<int>(k + 1, 0));
        pre[0][0]=1;
        for (int j = 1; j < n; j++) {
            pre[j][0]=1;
            for (int i = 1; i <= k; i++) {
                pre[j][i] = (pre[j-1][i]+pre[j-1][i-1])%m;
            }
        }
        int ans = 0;
        // first for min
        for (int i = 0; i < n; i++) {
            ans = (ans + nums[i]) % m;
            for (int j = 2; j <= k; j++) {
                int avail = pre[n-i-1][j - 1];
                int add = (avail * nums[i]) % m;
                ans = (ans + add) % m;
            }
        }
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            ans = (ans + nums[i]) % m;
            for (int j = 2; j <= k; j++) {
                int avail = pre[n-i-1][j - 1];
                int add = (avail * nums[i]) % m;
                ans = (ans + add) % m;
            }
        }
        return ans;
    }
};