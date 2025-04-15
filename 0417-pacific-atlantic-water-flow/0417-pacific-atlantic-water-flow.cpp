class Solution {
public:
    int m, n;
    
    set<pair<int, int>> bfs(queue<pair<int, int>>& q, vector<vector<int>>& heights) {
        set<pair<int, int>> visited;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (seen[r][c]) continue;

            seen[r][c] = true;
            visited.insert({r, c});

            for (auto [dr, dc] : directions) {
                int R = r + dr;
                int C = c + dc;

                if (R >= 0 && R < m && C >= 0 && C < n &&
                    !seen[R][C] && heights[R][C] >= heights[r][c]) {
                    q.push({R, C});
                }
            }
        }

        return visited;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        queue<pair<int, int>> pacificQ, atlanticQ;

        for (int i = 0; i < m; i++) {
            pacificQ.push({i, 0});
            atlanticQ.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            pacificQ.push({0, j});
            atlanticQ.push({m - 1, j});
        }

        set<pair<int, int>> pacific = bfs(pacificQ, heights);
        set<pair<int, int>> atlantic = bfs(atlanticQ, heights);

        vector<vector<int>> result;
        for (const auto& cell : pacific) {
            if (atlantic.count(cell)) {
                result.push_back({cell.first, cell.second});
            }
        }

        return result;
    }
};
