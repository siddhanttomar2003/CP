class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>&vis, vector<vector<char>>&g){
        return i>=0 && i<n && j>=0 && j<m && !vis[i][j] && g[i][j]=='O';
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
           if(board[i][0]=='O'){
               vis[i][0]=1;
               q.push({i,0});
           }
           if(board[i][m-1]=='O'){
               vis[i][m-1]=1;
               q.push({i,m-1});
           }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                vis[0][j]=1;
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }
        while(q.size()>0){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int n_r=r+delRow[k];
                int n_c=c+delCol[k];
                if(isValid(n_r,n_c,n,m,vis,board)){
                    vis[n_r][n_c]=1;
                    q.push({n_r,n_c});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])board[i][j]='X';
            }
        }

    }
};