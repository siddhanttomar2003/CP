class Solution {
public:
    // Check if k-size square can fit within grid bounds
    bool check(int i, int j, int k, int n, int m) {
        return (i + k <= n && j - k + 1 >= 0);
    }

    // Check if the k x k grid starting at (i, j) is a magic square
    bool exist(int i, int j, int k, vector<vector<int>>& grid) {
        int sum = 0;
        
        // First row sum (template)
        for (int l = j; l > j - k; l--) {
            sum += grid[i][l];
        }

        // Check rows for the same sum
        for (int l = i; l < i + k; l++) {
            int curr = 0;
            for (int g = j; g > j - k; g--) {
                curr += grid[l][g];
            }
            if (curr != sum) return false;
        }

        // Check columns for the same sum
        for (int l = j; l > j - k; l--) {
            int curr = 0;
            for (int g = i; g < i + k; g++) {
                curr += grid[g][l];
            }
            if (curr != sum) return false;
        }

        // Check left diagonal (top-right to bottom-left)
        int curr_l = 0;
        for (int l = 0; l < k; l++) {
            curr_l += grid[i + l][j - l];
        }
        if (curr_l != sum) return false;

        // Check right diagonal (top-left to bottom-right)
        int curr_r = 0;
        for (int l = 0; l < k; l++) {
            curr_r += grid[i + l][j - k + 1 + l];
        }
        if (curr_r != sum) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;

        // Iterate through all possible top-left corners (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Try squares of increasing size k
                for (int k = 2; k <= min(n, m); k++) {
                    if (check(i, j, k, n, m)) {
                        if (exist(i, j, k, grid)) {
                            ans = max(ans, k);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
