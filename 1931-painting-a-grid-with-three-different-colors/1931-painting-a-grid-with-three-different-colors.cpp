class Solution {
public:
    const int mod = 1e9 + 7;
    bool isValid(int i, int j, vector<vector<int>>& s) {
        int size = s[0].size();
        for (int k = 0; k < size; k++) {
            if (s[i][k] == s[j][k])
                return false;
        }
        return true;
    }
    void generate_state(int i, int m, vector<vector<int>>& v,
                        vector<int>& arr) {
        if (i == m) {
            v.push_back(arr);
            return;
        }
        for (int j = 0; j <= 2; j++) {
            if (i == 0) {
                arr[i] = j;
                generate_state(i + 1, m, v, arr);
            } else {
                if (j != arr[i - 1]) {
                    arr[i] = j;
                    generate_state(i + 1, m, v, arr);
                }
            }
        }
    }
    int dp[244][1001];
    int cal_ways(vector<vector<int>>& choice_for_col, int last_state, int col,
                 int n) {
        if (col == n)
            return 1;
        if (dp[last_state + 1][col] != -1)
            return dp[last_state + 1][col];
        int ways = 0;
        if (col == 0) {
            for (int j = 0; j < choice_for_col.size(); j++) {
                ways = (ways + cal_ways(choice_for_col, j, col + 1, n)) % mod;
            }
        } else {
            for (int j = 0; j < choice_for_col.size(); j++) {
                if (isValid(j, last_state,choice_for_col)) {
                    ways =
                        (ways + cal_ways(choice_for_col, j, col + 1, n)) % mod;
                }
            }
        }

        return dp[last_state + 1][col] = ways;
    }

    int colorTheGrid(int m, int n) {
        vector<vector<int>> v;
        vector<int> arr(m);
        generate_state(0, m, v, arr);
        memset(dp, -1, sizeof(dp));
        return cal_ways(v, -1, 0, n);
        return 0;
    }
};
