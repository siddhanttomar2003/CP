class Solution {
public:
    void recursion(vector<string>&board,vector<vector<string>>&ans,vector<int>&left_row,vector<int>&upper_diagonal,vector<int>&lower_diagonal,int n,int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(left_row[i]==0&&upper_diagonal[n-1+col-i]==0&&lower_diagonal[col+i]==0){
                left_row[i]=1;
                upper_diagonal[n-1+col-i]=1;
                lower_diagonal[col+i]=1;
                board[i][col]='Q';
                recursion(board,ans,left_row,upper_diagonal,lower_diagonal,n,col+1);
                board[i][col]='.';
                 left_row[i]=0;
                upper_diagonal[n-1+col-i]=0;
                lower_diagonal[col+i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<vector<string>>ans;
        vector<int>left_row(n,0);
        vector<int>upper_diagonal(2*n-1,0);
        vector<int>lower_diagonal(2*n-1,0);
        int col=0;
        recursion(board,ans,left_row,upper_diagonal,lower_diagonal,n,col);
        return ans;
    }
};