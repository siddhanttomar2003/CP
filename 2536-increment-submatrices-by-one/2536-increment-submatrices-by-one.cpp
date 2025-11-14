class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>l_s(n + 1, vector<int>(n + 1, 0));
        for(auto it : queries){
            int s = it[1];
            int e = it[3];
            int r_s = it[0];
            int r_e = it[2];
            for(int i = r_s; i <= r_e; i++){
            l_s[i][s]++;
            l_s[i][e + 1]--;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                l_s[i][j] += l_s[i][j - 1];
            }
        }
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = l_s[i][j];
            }
        }
        return ans;
    }
};