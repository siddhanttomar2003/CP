class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n, vector<int>(m, 0));
        int s_r = 0, s_c = 0, e_r = n - 1, e_c = m - 1;
        while(s_r <= e_r && s_c <= e_c){
            vector<vector<int>>temp;
            for(int i = s_c; i <= e_c; i++){
                temp.push_back({grid[s_r][i], s_r, i});
            }
            s_r++;
            for(int i = s_r; i <= e_r; i++){
                temp.push_back({grid[i][e_c], i, e_c});
            }
            e_c--;
            for(int i = e_c; i >= s_c; i--){
                temp.push_back({grid[e_r][i], e_r, i});
            }
            e_r--;
            for(int i = e_r; i >= s_r; i--){
                temp.push_back({grid[i][s_c], i, s_c});
            }
            s_c++;
            int size = temp.size();
            int curr = k % size;
            for(int i = 0; i < size; i++){
                auto it = temp[i];
                ans[it[1]][it[2]] = temp[(i + curr) % size][0];
            }
        }
        return ans;
        // 1, 2, 3, 4, 5, 6
    }
};