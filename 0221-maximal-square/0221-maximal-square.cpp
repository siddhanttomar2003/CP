class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>last_zero(n, vector<int>(m, m));
        for(int i = 0; i < n; i++){
            int last = m;
            for(int j = m - 1; j >= 0; j--){
                last_zero[i][j] = last;
                if(matrix[i][j] == '0')last = j;
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    int len = last_zero[i][j] - j;
                    // cout << len << endl;
                    ans = max(ans, 1);
                    for(int k = i + 1; k < n; k++){
                        if(matrix[k][j] == '1'){
                        int curr_len = last_zero[k][j] - j;
                        len = min(len, curr_len);
                        // cout << len << endl;
                        int a = k - i + 1;
                        if(len >= k - i + 1)ans = max(ans, a * a);
                        }
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};