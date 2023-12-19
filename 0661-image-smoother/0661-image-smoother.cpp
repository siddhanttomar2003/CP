class Solution {
public:
    // time/space: O(mn)/O(mn)
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int sum = 0, count = 0;
                for (int dr = -1; dr <= 1; dr++){
                    for (int dc = -1; dc <= 1; dc++) {
                        int nr = r + dr;
                        int nc = c + dc;
                        if ((nr < 0) || (nr >= m)) continue;
                        if ((nc < 0) || (nc >= n)) continue;
                        sum += img[nr][nc];
                        count++;
                    }
                }
                result[r][c] = (sum / count);
            }
        }
        return result;
    }
};