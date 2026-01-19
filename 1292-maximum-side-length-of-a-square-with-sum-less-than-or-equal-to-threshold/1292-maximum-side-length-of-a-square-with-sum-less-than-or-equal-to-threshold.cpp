class Solution {
public:
    bool check(int mid, vector<vector<int>>&pre, vector<vector<int>>&mat, int t){
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum = 0;
                if(i + mid <= n && j + mid <= m){
                    for(int k = i; k < i + mid; k++){
                        sum += pre[k][j + mid] - pre[k][j];
                    }
                    if(sum <= t)return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        vector<vector<int>>pre(n, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pre[i][j + 1] = pre[i][j] + mat[i][j];
                if(mat[i][j] <= threshold) ans = 1;
            }
        }
        int low = 1, high = min(n, m);
        // bool f = false;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, pre, mat, threshold)){
                ans = mid;
                // f = true;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};