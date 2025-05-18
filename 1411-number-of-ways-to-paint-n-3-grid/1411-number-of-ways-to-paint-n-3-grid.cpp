class Solution {
public:
    void generate_state(vector<vector<int>>& states, vector<int>& curr, int i,
                        int n) {
        if (i == n) {
            states.push_back(curr);
            return;
        }
        for (int j = 0; j <= 2; j++) {
            if (i == 0) {
                curr[i] = j;
                generate_state(states, curr, i + 1, n);
            } else {
                if (curr[i - 1] != j) {
                    curr[i] = j;
                    generate_state(states, curr, i + 1, n);
                }
            }
        }
    }
    int dp[13][5001];
    const int mod = 1e9 + 7;
    bool isValid(vector<vector<int>>& s, int last, int curr) {
        for (int i = 0; i < 3; i++) {
            if (s[last][i] == s[curr][i])
                return false;
        }
        return true;
    }
    int cal_ways(vector<vector<int>>& s, int row, int last_state, int n) {
        if (row == n)
            return 1;
        if (dp[last_state + 1][row] != -1)
            return dp[last_state + 1][row];
        int ways = 0;
        if (row == 0) {
            for (int j = 0; j < s.size(); j++) {
                ways = (ways + cal_ways(s, row + 1, j, n)) % mod;
            }
        } else {
            for (int j = 0; j < s.size(); j++) {
                if (isValid(s, last_state, j)) {
                    ways = (ways + cal_ways(s, row + 1, j, n)) % mod;
                }
            }
        }
        return dp[last_state + 1][row] = ways;
    }
    int numOfWays(int n) {
        // build all ways to paint any row and then treat them as a particular
        // option to place in each row
        vector<vector<int>> states;
        vector<int> curr(3);
        generate_state(states, curr, 0, 3);
        // for (auto it : states) {
        //     for (auto it2 : it)
        //         cout << it2 << " ";
        //     cout << endl;
        // }
        // now putting each state in each row with valid checking also
        // return 0;
        memset(dp,-1,sizeof(dp));
        return cal_ways(states,0,-1,n);
    }
};