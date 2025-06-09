class Solution {
public:
    
    bool isValid(int i , int j, int n , int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    bool dfs(vector<vector<char>>&b,int c_r, int c_c, string &word,vector<vector<int>>&vis,int i){
        vis[c_r][c_c]=1;
        if(i==word.size() || (b[c_r][c_c]==word[i] && i==word.size()-1))return true;
        bool check=false;
        if(word[i]==b[c_r][c_c]){
        int n=b.size();
        int m=b[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int n_r=c_r+delRow[k];
                int n_c=c_c+delCol[k];
                if(isValid(n_r,n_c,n,m) && !vis[n_r][n_c] ){
                   check|= dfs(b,n_r,n_c,word,vis,i+1);
                }
            }
        }    
            vis[c_r][c_c]=0;
            return check;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool check=false;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    check=dfs(board,i,j,word,vis,0);
                    if(check)return true;
                }
            }
        }
        return false;
    }
};
