class Solution {
public:
    vector<vector<int>>vis;
    bool isValid(int i, int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    void dfs(int i, int j, vector<vector<char>>&board, int n, int m){
        vis[i][j] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k ++){
            int n_r = delRow[k] + i;
            int n_c = delCol[k] + j;
            if(isValid(n_r, n_c, n, m) && board[n_r][n_c] == 'O' && !vis[n_r][n_c]){
                dfs(n_r, n_c, board, n, m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vis.clear();
        vis.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, board, n, m);
            }
            if(board[i][m - 1] == 'O' && !vis[i][m - 1]){
                dfs(i, m - 1, board, n, m);
            }
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, board, n, m);
            }
            if(board[n - 1][j] == 'O' && !vis[n - 1][j]){
                dfs(n - 1, j, board, n, m);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')board[i][j] = 'X';
            }
        }
    }
};