class Solution {
public:
    bool check(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    void build_teleports(vector<vector<pair<int, int>>>& mp,
                         vector<string>& grid, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]>='A' && grid[i][j]<='Z')
                mp[grid[i][j] - 'A'].push_back({i, j});
            }
        }
    }
    int minMoves(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        deque<vector<int>> dq;
        dq.push_back({0, 0, 0});
        vector<int> vis(26, 0);
        vector<vector<pair<int, int>>> mp(26);
        build_teleports(mp, grid, n, m);
        dq.push_back({0, 0, 0});
        while (dq.size() > 0) {
            auto it = dq.front();
            dq.pop_front();
            int curr_r = it[1];
            int curr_c = it[2];
            int curr_dis = it[0];
            if (grid[curr_r][curr_c] != '.' &&
                !vis[grid[curr_r][curr_c] - 'A']) {
                char c = grid[curr_r][curr_c];
                vis[c - 'A'] = 1;
                for (int j = 0; j < mp[c - 'A'].size(); j++) {
                    int l_r = mp[c - 'A'][j].first, l_c = mp[c - 'A'][j].second;
                    if (dis[l_r][l_c] > curr_dis) {
                        dis[l_r][l_c] = curr_dis;
                        dq.push_front({curr_dis, l_r, l_c});
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                int n_r = delRow[i] + curr_r;
                int n_c = delCol[i] + curr_c;
                if (check(n_r, n_c, n, m) && grid[n_r][n_c] != '#') {
                    if (dis[n_r][n_c] > 1 + curr_dis) {
                        dis[n_r][n_c] = 1 + curr_dis;
                        dq.push_back({dis[n_r][n_c], n_r, n_c});
                    }
                }
            }
        }
        if (dis[n - 1][m - 1] == 1e9)
            return -1;
        return dis[n - 1][m - 1];
    }
};