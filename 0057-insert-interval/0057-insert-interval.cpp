class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
             int curr_s=intervals[i][0],curr_e=intervals[i][1];
             if(curr_s<=e){
                e=max(e,curr_e);
             }
             else {
                ans.push_back({s,e});
                s=curr_s,e=curr_e;
             }
        }
        ans.push_back({s,e});
        return ans;
    }
};