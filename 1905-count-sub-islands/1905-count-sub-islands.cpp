class Solution {
public:
    void dfs2(int sr, int sc, map<pair<int, int>, int>& is_visited2,
              vector<vector<int>>& grid2, map<pair<int, int>, int>& is_visited,
              int n, int m, bool& check) {
        if (is_visited.find({sr, sc}) == is_visited.end()) {
            check = false;
        }
        is_visited2[{sr, sc}] = 1;
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nr = delRow[i] + sr;
            int nc = delCol[i] + sc;
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid2[nr][nc] &&
                is_visited2.find({nr, nc}) == is_visited2.end()) {
                dfs2(nr, nc, is_visited2, grid2, is_visited, n, m, check);
            }
        }
        return;
    }
    void dfs(vector<vector<int>>& grid, map<pair<int, int>, int>& is_visited,
             int sr, int sc, int n, int m) {
        is_visited[{sr, sc}] = 1;
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nr = delRow[i] + sr;
            int nc = delCol[i] + sc;
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] &&
                is_visited.find({nr, nc}) == is_visited.end()) {
                dfs(grid, is_visited, nr, nc, n, m);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        map<pair<int, int>, int> is_visited;
        int n = grid1.size();
        int m = grid1[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] == 1 &&
                    is_visited.find({i, j}) == is_visited.end()) {
                    dfs(grid1, is_visited, i, j, n, m);
                }
            }
        }
        int count = 0;
        map<pair<int, int>, int> is_visited2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] &&
                    is_visited2.find({i, j}) == is_visited2.end()) {
                    bool check = true;
                    dfs2(i, j, is_visited2, grid2, is_visited, n, m,
                         check) ;
                         if (check) count++;
                }
            }
        }

        return count;
    }
};