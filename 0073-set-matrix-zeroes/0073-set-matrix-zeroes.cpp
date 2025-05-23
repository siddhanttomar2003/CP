class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool check_first_col=false;
        bool check_first_row=false;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0)check_first_col=true;
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j]==0)check_first_row=true;
        }
        if(matrix[0][0]==0)check_first_col=check_first_row=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[0][i]==0){
                for(int j=1;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(check_first_col){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        if(check_first_row){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
    }
};
