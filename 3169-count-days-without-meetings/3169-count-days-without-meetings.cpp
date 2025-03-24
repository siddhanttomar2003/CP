class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        int ans=0;
        ans+=(meetings[0][0]-1);
        int s=meetings[0][0];
        int e=meetings[0][1];
        for(int i=1;i<n;i++){
            int curr_s=meetings[i][0],curr_e=meetings[i][1];
            if(curr_s>e)ans+=(curr_s-e-1);
            s=max(curr_s,s);
            e=max(e,curr_e);
        }
        ans+=(days-e);
        return ans;
    }
};