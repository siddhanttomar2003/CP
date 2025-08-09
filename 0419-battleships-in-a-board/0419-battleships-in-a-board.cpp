class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    void dfs(int r, int c, vector<vector<char>>&board, vector<vector<int>>&vis, int n, int m){
        vis[r][c] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++){
            int n_r = r + delRow[k];
            int n_c = c + delCol[k];
            if(isValid(n_r, n_c, n, m) && board[n_r][n_c] == 'X' && !vis[n_r][n_c]){
                dfs(n_r, n_c, board, vis, n, m);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'X'){
                    count++;
                    dfs(i, j, board, vis, n, m);
                }
            }
        }
        return count;
    }
};