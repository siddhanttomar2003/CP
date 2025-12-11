class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        map<int, set<int>>x, y;
        for(auto it : b){
            x[it[0]].insert(it[1]);
            y[it[1]].insert(it[0]);
        }
        int ans = 0;
        for(auto it : b){
            int curr_x = it[0];
            int curr_y = it[1];
            auto it1 = x[curr_x].upper_bound(curr_y);
            auto it2 = x[curr_x].lower_bound(curr_y);
            auto it3 = y[curr_y].lower_bound(curr_x);
            auto it4 = y[curr_y].upper_bound(curr_x);
            if(it1 == x[curr_x].end() || it2 == x[curr_x].begin() || it3 == y[curr_y].begin() || it4 == y[curr_y].end())continue;
            ans++;
        }
        return ans;
    }
};