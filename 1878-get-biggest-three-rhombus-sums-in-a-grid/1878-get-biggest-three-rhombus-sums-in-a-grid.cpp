class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int>ans;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum = grid[i][j];
                int times = 0;
                int l_r = i + 1, l_c = j - 1;
                int r_r = i + 1, r_c = j + 1;
                ans.insert(sum);
                while(l_r < n && l_c >= 0 && r_r < n && r_c < m){
                    times++;
                    sum += grid[l_r][l_c];
                    sum += grid[r_r][r_c];
                    int sl_r = l_r + 1, sl_c = l_c + 1;
                    int sr_r = l_r + 1, sr_c = r_c - 1;
                    int f = times;
                    int sum2 = 0;
                    while(f > 0 && sl_r < n && sr_r < n && sl_c >= 0 && sr_c < m && sl_c <= sr_c){
                        if(sl_c != sr_c)
                        sum2 += grid[sl_r][sl_c];
                        sum2 += grid[sr_r][sr_c];
                        f--;
                        sl_r++;
                        sr_r++;
                        sl_c++;
                        sr_c--;
                        if(f == 0)ans.insert(sum + sum2);
                    }
                   l_r++;
                   r_r++;
                   l_c--;
                   r_c++;
                }
            }
        }
       vector<int>fans;
       for(auto it = ans.rbegin(); it != ans.rend(); it++){
            fans.push_back(*it);
            if(fans.size() == 3)break;
       }
       return fans;
    }
};