class Solution {
public:
    map<pair<int, int>, int>mp;
    bool valid(int i, int j, int r, int c){
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    bool check(int m, int r, int c){
        set<pair<int, int>>vis;
        queue<pair<int, int>>q;
        for(int i = 0; i < c; i++){
            if(mp.find({0, i}) != mp.end() && mp[{0, i}] <= m){
                continue;
            }
            else {
                q.push({0, i});
                vis.insert({0, i});
            }
        }
        while(q.size() > 0){
            auto it = q.front();
            q.pop();
            int row = it.first, col = it.second;
            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int nr = row + delRow[i];
                int nc = col + delCol[i];
                if(valid(nr, nc, r, c) && vis.find({nr, nc}) == vis.end()){
                    if(mp.find({nr, nc}) != mp.end() && mp[{nr, nc}] <= m)continue;
                    else {
                        vis.insert({nr, nc});
                        q.push({nr, nc});
                    }
                }
            }
        }
        for(int i = 0; i < c; i++){
            if(vis.find({r - 1, i}) != vis.end())return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        for(int i = 0; i < cells.size(); i++){
            mp[{cells[i][0] - 1, cells[i][1] - 1}] = i + 1;
        }
        int ans = 1;
        int low = 1;
        int high = 1e5;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, row, col)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};