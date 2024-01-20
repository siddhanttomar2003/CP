class Solution {
public:
     bool floodfill_algo(vector<vector<char>>& board,int sr,int sc,string word,int index,int m,int n){
         if(index==word.size())return true;
         if(sr<0||sc<0||sr==m||sc==n||board[sr][sc]!=word[index])return false;
         char ch=board[sr][sc];
         board[sr][sc]='#';
         bool a=floodfill_algo(board,sr+1,sc,word,index+1,m,n);
         bool b=floodfill_algo(board,sr-1,sc,word,index+1,m,n);
         bool c=floodfill_algo(board,sr,sc+1,word,index+1,m,n);
         bool d=floodfill_algo(board,sr,sc-1,word,index+1,m,n);
         board[sr][sc]=ch;
         return a||b||c||d;
     }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
         int index=0;
         int s=0;
         // to find the starting of the word
    
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(board[i][j]==word[0]){
                     int sr=i;
                     int sc=j;
                     int index=0;
                     if(floodfill_algo(board,sr,sc,word,index,m,n)==true)return true;
                 }
             }
         }
         return false;

    }
};