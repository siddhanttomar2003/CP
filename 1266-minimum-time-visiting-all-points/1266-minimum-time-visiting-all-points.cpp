class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;
        for(int i=0;i<points.size()-1;i++){
            int a[2]={points[i][0],points[i][1]};
            int b[2]={points[i+1][0],points[i+1][1]};
            int dist_x=abs(b[0]-a[0]);
            int dist_y=abs(b[1]-a[1]);
            int mini=min(dist_x,dist_y);
            time+=min(dist_x,dist_y);
            int maxi=max(dist_x,dist_y);
            time+=abs(maxi-mini);
        }
        return time;
    }
};