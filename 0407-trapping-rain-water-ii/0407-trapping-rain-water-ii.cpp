#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<int>> up_arr(n, vector<int>(m));
        vector<vector<int>> low_arr(n, vector<int>(m));
        vector<vector<int>> left_arr(n, vector<int>(m));
        vector<vector<int>> right_arr(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            up_arr[0][i] = h[0][i];
            low_arr[n - 1][i] = h[n - 1][i];
        }

        for (int i = 0; i < n; i++) {
            left_arr[i][0] = h[i][0];
            right_arr[i][m - 1] = h[i][m - 1];
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                up_arr[i][j] = max(up_arr[i - 1][j], h[i][j]);
                low_arr[n - i - 1][j] = max(low_arr[n - i][j], h[n - i - 1][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m - 1; j++) {
                left_arr[i][j] = max(left_arr[i][j - 1], h[i][j]);
                right_arr[i][m - j - 1] = max(right_arr[i][m - j], h[i][m - j - 1]);
            }
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                int mini = min({left_arr[i][j], right_arr[i][j], up_arr[i][j], low_arr[i][j]});
                if (mini > h[i][j]) ans += (mini - h[i][j]);
            }
        }

        return ans;
    }
};
