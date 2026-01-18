class Solution {
public:
    bool check(int i, int j, int k, int n, int m) {
        if (i + k > n ||  j - k +1< 0)
            return false;
        return true;
    }
    bool exist(int i, int j, int k, int n, int m, vector<vector<int>>& grid) {
        // check row;
        // first row set as a template to check everything
        int sum = 0;
        for (int l = j; l > j - k; l--) {
            sum += grid[i][l];
        }
        for (int l = i; l < i + k; l++) {
            int curr = 0;
            for (int g = j; g > j - k; g--) {
                curr += grid[l][g];
            }
            if(curr!=sum)return false;
        }

        // check for every col
        for(int l=j-k+1;l<j;l++){
            int curr=0;
            for(int g=i;g<i+k;g++){
                curr+=grid[g][l];
            }
            if(curr!=sum)return false;
        }

        // check for left diagonal
        int curr_l = 0;
        int l = i;
        int r = j;
        int t = k;
        while (t--) {
            curr_l += grid[l][r];
            l++;
            r--;
        }
        if (curr_l != sum)
            return false;
        // check for right diagonal
        j = j - k+ 1;
        int curr_r = 0;
        int g = k;
        while (g--) {
            curr_r += grid[i][j];
            i++;
            j++;
        }
        if (curr_r != sum)
            return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 2; k <= min(n,m); k++) {
                    if (check(i, j, k, n, m)) {
                        if (exist(i, j, k, n, m, grid)) {
                            ans = max(ans, k);
                        }
                    }
                }
            }
        }
        return ans;
    }
};