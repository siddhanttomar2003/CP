class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size(), m = grid[0].size();
        int s_r = x, e_r = x + k - 1;
        int s_c = y, e_c = y + k - 1;
        while(s_r < e_r){
            for(int i = s_c; i <= e_c; i++){
                swap(grid[s_r][i], grid[e_r][i]);
            }
            s_r++;
            e_r--;
        }
        return grid;
    }
};