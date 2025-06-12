class Solution {
public:
    int row[9],ld[18],ud[18];
    int cal(int col, int n){
        if(col==n)return 1;
        int ways=0;
        for(int j=0;j<n;j++){
            if(!row[j] && !ud[col+j] && !ld[col-j+n]){
                row[j]=1;
                ud[col+j]=1;
                ld[col-j+n]=1;
                ways+=cal(col+1,n);
                row[j]=0;
                ud[col+j]=0;
                ld[col-j+n]=0;
            }
        }
        return ways;
    }
    int totalNQueens(int n) {
        memset(row,0,sizeof(row));
        memset(ld,0,sizeof(ld));
        memset(ud,0,sizeof(ud));
       return cal(0,n);
    }
};