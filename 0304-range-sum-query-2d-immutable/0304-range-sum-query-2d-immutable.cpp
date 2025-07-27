class NumMatrix {
public:
    vector<vector<int>>pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        pre.resize(n, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                pre[i][j + 1] = pre[i][j] + matrix[i][j]; 
            } 
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            sum += pre[i][col2 + 1] - pre[i][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */