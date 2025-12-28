class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            int j = 0, k = m - 1;
            while(j <= k){
                int mid = j + (k - j) / 2;
                if(grid[i][mid] < 0)k = mid - 1;
                else j = mid + 1;
            }
            ans += m - j;
        }
        return ans;
    }
};