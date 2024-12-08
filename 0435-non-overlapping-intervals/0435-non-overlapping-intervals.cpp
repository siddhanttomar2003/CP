class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=0;
        sort(intervals.begin(),intervals.end(),[](vector<int>a, vector<int>b){
            return a[1]<b[1];
        });
        int last=intervals[0][1];
        int curr=1;
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            if(start>=last){
                curr++;
                last=intervals[i][1];
            }
        }
        return n-curr;
    }
};