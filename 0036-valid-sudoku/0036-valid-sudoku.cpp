class Solution {
public:
    bool check(char d, vector<vector<int>>&r, vector<vector<int>>&c,vector<vector<int>>&sub,int i,int j){
       int num=d-'1';
       if(!r[i][num]){
          r[i][num]=1;
       }
       else return false;
       if(!c[j][num]){
         c[j][num]=1;
       }
       else return false;
       if(!sub[((i/3)*3)+(j/3)][num]){
        sub[((i/3)*3)+(j/3)][num]=1;
       }
       else return false;
       return true;
    }
    bool isValid(vector<vector<char>>&b,vector<vector<int>>&r,vector<vector<int>>&c,vector<vector<int>>&sub, int col , int m){
        bool flag=true;
        if(col==m)return flag;
        for(int i=0;i<9;i++){
            if(b[i][col]!='.'){
                if(check(b[i][col],r,c,sub,i,col)){
                   continue;
                }
                else flag=false;
            }
        }
        if(!flag)return flag;
        else return flag &=isValid(b,r,c,sub,col+1,m);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        vector<vector<int>>row(n,vector<int>(9,0)),col(n,vector<int>(9,0)),sub_box(n,vector<int>(9,0));
        // will try to move row wise and then next col
        return isValid(board,row,col,sub_box,0,9);
    }
};
