class Solution {
public:
    typedef long long ll;
    int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>pre(n, 0);
        ll mul = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                mul = (mul * grid[i][j]) % mod;
            }
            pre[i] = mul;
        }
        mul = 1;
        for(int i = 0; i < n; i++){
            vector<int>temp(m, 0);
            ll curr1 = 1;
            for(int j = m - 1; j >= 0; j--){
                curr1 = (curr1 * grid[i][j]) % mod;
                temp[j] = curr1;
            }
            
            ll curr2 = 1;
            ll cal = 1;
            if(i != n - 1)cal = pre[i + 1];
            if(i != 0)cal = (cal * mul) % mod;
            mul = (mul * curr1) % mod;
            for(int j = 0; j < m; j++){
                ll t = grid[i][j];
                if(j == m - 1)grid[i][j] = (curr2 * cal) % mod;
                else if(j == 0)grid[i][j] = (cal * temp[j + 1]) % mod;
                else {
                    grid[i][j] = (((cal * curr2) % mod)*temp[j + 1]) % mod;
                }
                curr2 = (curr2 * t) % mod;
            }
        }
        return grid;
    }
};