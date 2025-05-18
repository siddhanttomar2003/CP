#include <array>
#include <vector>
class Solution {
public:
    bool solve(vector<vector<char>>& b, vector<vector<int>>& r,
               vector<vector<int>>& c, vector<vector<int>>& sub, int row,
               int col, int m) {
        if (col == m)
            return true;

        for (int i = row; i < 9; i++) {
            if (b[i][col] == '.') {

                for (char j = '1'; j <= '9'; j++) {
                    int num = j - '1';
                    if (!r[i][num] && !c[col][num] &&
                        !sub[(i / 3 * 3 + col / 3)][num]) {
                        r[i][num] = 1;
                        c[col][num] = 1;
                        sub[(i / 3 * 3 + col / 3)][num] = 1;
                        b[i][col] = j;
                        if (solve(b, r, c, sub, i + 1, col, m)) {
                            return true;
                        }
                        b[i][col] = '.';
                        r[i][num] = 0;
                        c[col][num] = 0;
                        sub[(i / 3 * 3 + col / 3)][num] = 0;
                    }
                }
                return false;
            }
        }
        return solve(b, r, c, sub, 0, col + 1, m);
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> sub(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    sub[((i / 3) * 3) + j / 3][num] = 1;
                }
            }
        }
        solve(board, row, col, sub, 0, 0, 9);
    }
};
