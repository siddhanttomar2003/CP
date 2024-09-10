class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0];
        int e=intervals[0][1];
        int n=intervals.size();
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
           int curr_e=intervals[i][1];
           int curr_s=intervals[i][0];
           if(curr_s<=e){
            e=max(e,curr_e);
           }
           else {
            ans.push_back({s,e});
            s=curr_s;
            e=curr_e;
           }
        }
        ans.push_back({s,e});
        return ans;
    }
};