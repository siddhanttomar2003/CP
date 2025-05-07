typedef long long ll;
class Solution {
public:
    bool check(int i , int j , int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<ll>> dis(n, vector<ll>(m, 1e10));
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        pq.push({0, 0, 0});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while (pq.size() > 0) {
            auto it = pq.top();
            pq.pop();
            ll curr_time = it[0];
            int curr_r = it[1];
            int curr_c = it[2];
            for (int i = 0; i < 4; i++) {
                int n_r = curr_r + delRow[i];
                int n_c = curr_c + delCol[i];
                if (check(n_r, n_c, n, m)) {
                    if (curr_time + 1 > moveTime[n_r][n_c] &&
                        dis[n_r][n_c] > curr_time + 1) {
                        dis[n_r][n_c] = curr_time + 1;
                        pq.push({curr_time + 1, n_r, n_c});
                    } else if (curr_time + 1 <= moveTime[n_r][n_c]) {
                        if (dis[n_r][n_c] > moveTime[n_r][n_c]+1) {
                            dis[n_r][n_c] = moveTime[n_r][n_c]+1;
                            pq.push({moveTime[n_r][n_c]+1, n_r, n_c});
                        }
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};