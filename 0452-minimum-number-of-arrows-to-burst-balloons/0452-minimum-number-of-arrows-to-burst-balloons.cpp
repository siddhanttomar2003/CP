class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>>ans;
        ans.push_back(points[0]);
        int j=0;
        for(int i=1;i<points.size();i++){
            if(ans[j][1]>=points[i][0]){
                ans[j][1]=min(points[i][1],ans[j][1]);
            }
            else{
                ans.push_back(points[i]);
                j++;
            }
        }
        return ans.size();
    }
};