class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int max_width=-1;
        for(int i=0;i<points.size()-1;i++){
            if(abs(points[i][0]-points[i+1][0])>max_width){
                max_width=abs(points[i][0]-points[i+1][0]);
            }
        }
        return max_width;
    }
};