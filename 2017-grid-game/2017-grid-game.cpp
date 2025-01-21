class Solution {
public:
    long long dijkstra2(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> dis(2, vector<long long>(n, -1));
        dis[0][0] = 0;
        priority_queue<vector<long long>>pq;
        pq.push({0, 0, 0});
        while (pq.size() > 0) {
            long long curr_dis = pq.top()[0];
            int curr_x = pq.top()[1];
             int curr_y = pq.top()[2];
            pq.pop();
            if (curr_x + 1 < 2 &&
                dis[curr_x + 1][curr_y] < curr_dis + grid[curr_x + 1][curr_y]) {
                dis[curr_x + 1][curr_y] = curr_dis + grid[curr_x + 1][curr_y];
                pq.push({dis[curr_x + 1][curr_y], curr_x + 1, curr_y});
            }
            if (curr_y + 1 < n &&
                dis[curr_x][curr_y + 1] < curr_dis + grid[curr_x][curr_y + 1]) {
                dis[curr_x][curr_y + 1] = curr_dis + grid[curr_x][curr_y + 1];
                pq.push({dis[curr_x][curr_y + 1], curr_x, curr_y + 1});
            }
        }
        return dis[1][n-1];

    }
    void dijkstra(vector<vector<int>>& grid,
                  map<pair<int, int>, pair<int, int>>& child_par) {
       
        priority_queue<vector<long long>>pq;
        int curr = grid[0][0];
        pq.push({curr, 0, 0});
        int n = grid[0].size();
        vector<vector<long long>> dis(2, vector<long long>(n, -1));
        dis[0][0] = 0;
        while (pq.size() > 0) {
            long long curr_dis = pq.top()[0];
            int curr_x = pq.top()[1];
            int curr_y = pq.top()[2];
            pq.pop();
            if (curr_x + 1 < 2 &&
                dis[curr_x + 1][curr_y] < curr_dis + grid[curr_x + 1][curr_y]) {
                dis[curr_x + 1][curr_y] = curr_dis + grid[curr_x + 1][curr_y];
                child_par[{curr_x + 1,curr_y}] = {curr_x, curr_y};
                pq.push({dis[curr_x + 1][curr_y], curr_x + 1, curr_y});
            }
            if (curr_y + 1 < n &&
                dis[curr_x][curr_y + 1] < curr_dis + grid[curr_x][curr_y + 1]) {
                dis[curr_x][curr_y + 1] = curr_dis + grid[curr_x][curr_y + 1];
                child_par[{curr_x,curr_y + 1}] = {curr_x, curr_y};
                pq.push({dis[curr_x][curr_y + 1], curr_x, curr_y + 1});
            }
        }
        int c_y = n - 1;
        int c_x = 1;
        pair<int,int>temp={0,0};
        while (child_par[{c_x, c_y}] !=temp) {
            // cout<<c_x<<" "<<c_y<<" "<<child_par[{c_x,c_y}].first<<" "<<child_par[{c_x,c_y}].second<<endl;
            grid[c_x][c_y] = 0;
            pair<int, int> par = child_par[{c_x, c_y}];
            c_x = par.first;
            c_y = par.second;
        }
        grid[c_x][c_y]=0;
        grid[0][0] = 0;
        grid[1][n - 1] = 0;
    }
    long long gridGame(vector<vector<int>>& grid) {
        map<pair<int, int>, pair<int, int>> child_par;
        child_par[{0, 0}] = {0, 0};
        dijkstra(grid, child_par);
        for(int i=0;i<2;i++){
            for(int j=0;j<grid[i].size();j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return dijkstra2(grid);
    }
};