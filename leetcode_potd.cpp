class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>one_row(row,0);
        vector<int>one_col(col,0);
        vector<int>zero_row(row,0);
        vector<int>zero_col(col,0);
         for(int i=0;i<row;i++){
             for(int j=0;j<col;j++){
                 if(grid[i][j]==1){
                     one_row[i]++;
                     one_col[j]++;
                 }
                 else {
                     zero_row[i]++;
                     zero_col[j]++;
                 }
             }
         }
         for(int i=0;i<row;i++){
             for(int j=0;j<col;j++){
                 grid[i][j]=one_row[i]+one_col[j]-zero_row[i]-zero_col[j];
             }
         }
         return grid;
    }
};