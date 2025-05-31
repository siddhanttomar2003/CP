class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int new_size = n * n;
        vector<int> nboard(new_size + 1);
        int curr = 1;
        int level = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (level & 1) {
                for (int j = n - 1; j >= 0; j--) {
                    nboard[curr] = board[i][j];
                    curr++;
                }
            } else {
                for (int j = 0; j < n; j++) {
                    nboard[curr] = board[i][j];
                    curr++;
                }
            }
            level++;
        }
        
        vector<int> dis(new_size + 1, 1e9);
        dis[1] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 1});
        while (pq.size() > 0) {
            int par = pq.top()[1];
            int steps = pq.top()[0];
            pq.pop();
            for (int i = 1; i <= 6; i++) {
                if (par + i <= new_size) {
                    int new_par = par + i;
                    if (nboard[new_par] != -1)
                        new_par = nboard[new_par];
                    if (dis[new_par] > steps + 1) {
                        dis[new_par] = steps + 1;
                        pq.push({steps + 1, new_par});
                    }
                }
            }
        }
        if (dis[new_size] == 1e9)
            return -1;
        return dis[new_size];
    }
};