class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        bool check_h = false;
        vector<pair<int, int>> y_cor, x_cor;
        for (int i = 0; i < rectangles.size(); i++) {
            int x1 = rectangles[i][0];
            int x2 = rectangles[i][2];
            int y1 = rectangles[i][1];
            int y2 = rectangles[i][3];
            x_cor.push_back({x1, x2});
            y_cor.push_back({y1, y2});
        }
        sort(x_cor.begin(), x_cor.end());
        sort(y_cor.begin(), y_cor.end());
        int count_y = 0, count_x = 0;
        int s_y = y_cor[0].first;
        int e_y = y_cor[0].second;
        for (int i = 1; i < y_cor.size(); i++) {
            int cs_y = y_cor[i].first;
            int ce_y = y_cor[i].second;
            if (cs_y >= e_y) {
                count_y++;

            }
            e_y=max(e_y,ce_y);
            s_y=max(s_y,cs_y);
        }
          int s_x=x_cor[0].first;
        int e_x=x_cor[0].second;
        for (int i = 1; i < x_cor.size(); i++) {
            int cs_x = x_cor[i].first;
            int ce_x = x_cor[i].second;
            if (cs_x >= e_x) {
                count_x++;

            }
            e_x=max(e_x,ce_x);
            s_x=max(s_x,cs_x);
        }
        if(count_x>=2 || count_y>=2)return true;
        return false;
    }
};