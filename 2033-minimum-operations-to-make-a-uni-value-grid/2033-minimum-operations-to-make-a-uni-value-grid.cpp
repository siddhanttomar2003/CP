class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        set<int>st;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                st.insert(grid[i][j] % x);
                if(st.size() > 1)return -1;
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        vector<int>pre(n * m + 1, 0);
        for(int i = 0; i < ans.size(); i++){
            pre[i + 1] = pre[i] + ans[i];
        }
        int mini = 1e9;
        for(int i = 0; i < ans.size(); i++){
            int left = pre[i], right = pre[n * m] - pre[i + 1];
            int curr = ans[i];
            mini = min(mini, (((i * curr) - (left)) / x) +  (right - ((n * m - (i + 1)) * curr)) / x);
        }
        return mini;
    }
};