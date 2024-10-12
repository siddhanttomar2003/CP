class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int,vector<int>,greater<int>> heap;
        int ans = 1;
		heap.push(intervals[0][1]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= heap.top()){
                heap.push(intervals[i][1]);
            }
            else{
                heap.pop();
                heap.push(intervals[i][1]);
            }
        }
        return heap.size();
    }
};