class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>>ans;
       bool check=false;
       int i=0;
       for(i;i<intervals.size();i++){
          if(intervals[i][0]>newInterval[1]){
            ans.push_back(newInterval);
            check=true;
            break;
          }
          else if(newInterval[0]>intervals[i][1]){
            ans.push_back(intervals[i]);
          }
          else {
                   int start=min(newInterval[0],intervals[i][0]);
                   int end=max(newInterval[1],intervals[i][1]);
                   check=true;
                   i++;
                   for(i;i<intervals.size();i++){
                      int curr_s=intervals[i][0];
                      int curr_e=intervals[i][1];
                      if(curr_s<=end){
                        end=max(end,curr_e);
                      }
                      else {
                      
                        break;
                      }
                   }
                   ans.push_back({start,end});
                   break;
          }
       }
       for(i;i<intervals.size();i++)ans.push_back(intervals[i]);
       if(!check)ans.push_back(newInterval);
       return ans;
    }
};