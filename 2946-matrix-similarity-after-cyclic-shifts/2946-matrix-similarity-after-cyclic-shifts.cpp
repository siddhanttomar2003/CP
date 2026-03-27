class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        // 5 4 3 2 1 <- 1 2 3 4 5 -> 5 4 3 2 1
        // 4 5 1 2 3
        // 3 4 5 1 2
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>temp = mat;
        k %= m;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                reverse(mat[i].begin(), mat[i].end());
                reverse(mat[i].begin(), mat[i].begin() + m - k);
                reverse(mat[i].begin() + m - k, mat[i].end());
            }
            else {
                reverse(mat[i].begin(), mat[i].end());
                reverse(mat[i].begin(), mat[i].begin() + k);
                reverse(mat[i].begin() + k, mat[i].end());
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != temp[i][j])return false;
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
};