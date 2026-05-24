class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>>pre(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // pre[i][j][k] -> in ith row max_value in the range from j to k
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int maxi = 0;
                for(int k = j; k < m; k++){
                    maxi = max(maxi, mat[i][k]);
                    pre[i][j][k] = maxi;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int lim = mat[i][j];
                if(lim == 0)continue;
                int s_r = max(i - lim, 0);
                int s_c = max(j - lim, 0);
                int e_r = min(i + lim, n - 1);
                int e_c = min(j + lim, m - 1);
                int maxi = 0;
                while(s_r <= e_r){
                    if(s_r == i - lim || s_r == i + lim){
                        int c_s = s_c;
                        int c_e = e_c;
                        if(j - lim == s_c)c_s++;
                        if(j + lim == e_c)c_e--;
                        maxi = max(maxi, pre[s_r][c_s][c_e]);
                    }
                    else {
                        maxi = max(maxi, pre[s_r][s_c][e_c]);
                    }
                    s_r++;
                }
                if(maxi <= lim)count++;
            }
        }
        return count;
    }
};