class Solution {
public:
    int cal_area(int x1, int x2, int x3, int x4, int y1, int y2, int y3,
                 int y4) {
        map<int, int> x;
        map<int, int> y;
        x[x1]++;
        x[x2]++;
        x[x3]++;
        x[x4]++;
        y[y1]++;
        y[y2]++;
        y[y3]++;
        y[y4]++;
    
        int len=max(abs(x2-x1),abs(x2-x3));
        int br=max(abs(y2-y1),abs(y2-y3));
        return len*br;
    }
    bool isRectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3,
                     int y4,vector<vector<int>>&points) {
        map<int, int> x;
        map<int, int> y;
        map<pair<int,int>,int>mp;
       
        x[x1]++;mp[{x1,y1}]++;mp[{x2,y2}]++;mp[{x3,y3}]++;mp[{x4,y4}]++;
        x[x2]++;
        x[x3]++;
        x[x4]++;
        y[y1]++;
        y[y2]++;
        y[y3]++;
        y[y4]++;
        int sx=min({x1,x2,x3,x4});
        int lx=max({x1,x2,x3,x4});
         int sy=min({y1,y2,y3,y4});
        int ly=max({y1,y2,y3,y4});
        

        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            if(mp.find({x,y})==mp.end()){
                if(x>=sx && x<=lx && y<=ly && y>=sy)return false;
            }

        }
        if (x.size() == 2 && y.size() == 2) {
            for (auto it : x) {
                if (it.second != 2)
                    return false;
            }
            for (auto it : y) {
                if (it.second != 2)
                    return false;
            }
            return true;
        }
        return false;
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int maxi = 0;
        int n=points.size();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            int x3 = points[k][0];
                            int y3 = points[k][1];
                            for (int l = 0; l < n; l++) {
                                if (l != i && l != j && l != k) {
                                    int x4 = points[l][0];
                                    int y4 = points[l][1];
                                    if (isRectangle(x1, x2, x3, x4, y1, y2, y3,
                                                    y4,points)) {
                                        maxi =
                                            max(maxi, cal_area(x1, x2, x3, x4,
                                                               y1, y2, y3, y4));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(maxi==0)return -1;
        return maxi;
    }
};