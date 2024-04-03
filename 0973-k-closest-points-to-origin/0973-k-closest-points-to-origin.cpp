class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>>maxh;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            double dis=sqrt(x*x+y*y);
            pair<int,int>p;
            p.first=x;
            p.second=y;
            maxh.push({dis,p});
            if(maxh.size()>k)maxh.pop();
        }
        vector<vector<int>>ans;
        while(maxh.size()>0){
              vector<int>v;
              v.push_back(maxh.top().second.first);
              v.push_back(maxh.top().second.second);
                ans.push_back(v);
                maxh.pop();
        }
        return ans;
    }
};