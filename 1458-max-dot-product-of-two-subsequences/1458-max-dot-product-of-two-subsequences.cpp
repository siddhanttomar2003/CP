class Solution {
public:
    int dp[501][501][2];
    int cal(int i, int j, int n, int m, vector<int>&arr1, vector<int>&arr2, int taken){
        if(i == n || j == m){
            if(taken)return 0;
            return -1e9;
        }
        if(dp[i][j][taken] != -1)return dp[i][j][taken];
        int mini = -2e9;
        mini = max(mini, arr1[i] * arr2[j] + cal(i + 1, j + 1, n, m, arr1, arr2, 1));
        mini = max(mini, cal(i + 1, j, n, m, arr1, arr2, taken));
        mini = max(mini, cal(i,j + 1, n, m, arr1, arr2, taken));
        return dp[i][j][taken] = mini;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        int n = nums1.size(), m = nums2.size();
        int ans = cal(0, 0, n, m, nums1, nums2, 0);
        return ans;
    }
};