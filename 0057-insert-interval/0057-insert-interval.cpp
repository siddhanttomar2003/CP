class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // inserting previous non overlapping
        int i=0,n=intervals.size();
        vector<vector<int>>ans;
        while(i<n && newInterval[0]>intervals[i][1]){
             ans.push_back(intervals[i]);
             i++;
        }
        // merging overlapping one
        if(i<n && intervals[i][0]<=newInterval[1]){
              int start=min(intervals[i][0],newInterval[0]);
              int end=max(intervals[i][1],newInterval[1]);
              i++;
              while(i<n && intervals[i][0]<=end){
                  end=max(end,intervals[i][1]);
                  i++;
              }
              ans.push_back({start,end});
        }

        else ans.push_back(newInterval);
        // filling non overlapping at the ends
        while(i<n)ans.push_back(intervals[i++]);
        
        return ans;
    }
};