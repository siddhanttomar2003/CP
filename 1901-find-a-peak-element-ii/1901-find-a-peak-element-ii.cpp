class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int low = 0, high = m - 1;
        int n = mat.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            cout << mid << endl;
            int maxi = -1;
            int pos = -1;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > maxi) {
                    maxi = mat[i][mid];
                    pos = i;
                }
            }
            bool check_left = true, check_right = true;
            if (mid - 1 >= 0 && mat[pos][mid - 1] > mat[pos][mid])
                check_left = false;
            if (mid + 1 < m && mat[pos][mid + 1] > mat[pos][mid])
                check_right = false;
            if (check_left && check_right)
                return {pos, mid};
            if (mid - 1 >= 0 && mat[pos][mid] > mat[pos][mid - 1] || mid == 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};