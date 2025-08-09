class Solution {
public:
    vector<vector<int>>f_time;
    bool isValid(int i, int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    void cal(vector<vector<int>>&grid, int n, int m){
        queue<vector<int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({0, i, j});
                    f_time[i][j] = 0;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(q.size() > 0){
            auto it = q.front();
            int r = it[1];
            int c = it[2];
            int t = it[0];
            q.pop();
            for(int k = 0; k < 4; k++){
                int n_r = r + delRow[k];
                int n_c = c + delCol[k];
                if(isValid(n_r, n_c, n, m) && grid[n_r][n_c] == 0 && f_time[n_r][n_c] > t + 1){
                    f_time[n_r][n_c] = t + 1;
                    q.push({t + 1, n_r, n_c});
                }
            }
        }
    }
    bool check(int maxi, int r, int c, int n, int m, vector<vector<int>>&grid){
        queue<vector<int>>q;
        q.push({maxi, 0, 0});
        if(maxi > f_time[0][0])return false;
        vector<vector<int>>dis(n, vector<int>(m, 1e9));
        dis[0][0] = maxi;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(q.size() > 0){
            auto it = q.front();
             int r = it[1];
            int c = it[2];
            int curr = it[0];
            q.pop();
            for(int k = 0; k < 4; k++){
                int n_r = r + delRow[k];
                int n_c = c + delCol[k];
                if(isValid(n_r, n_c, n, m) && grid[n_r][n_c] != 2 && dis[n_r][n_c] > curr + 1 && (curr + 1 < f_time[n_r][n_c] || curr + 1 == f_time[n_r][n_c] && n_r == n - 1 && n_c == m - 1)){
                    dis[n_r][n_c] = curr + 1;
                    q.push({curr + 1, n_r, n_c});
                }
            }
        }
        if(dis[n - 1][m - 1] != 1e9)return true;
        return false;

    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        f_time.clear();
        f_time.resize(n, vector<int>(m, 1e9));
        cal(grid, n, m);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++)cout << f_time[i][j] << " ";
        //     cout << endl;
        // }
        int low = 0, high = n * m + 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, 0, 0, n, m, grid)){
                ans = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        return ans > n * m ? 1e9 : ans;
    }
};