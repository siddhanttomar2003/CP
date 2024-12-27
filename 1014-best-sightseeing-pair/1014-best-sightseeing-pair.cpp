class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        priority_queue<int>pq;
        int ans=-1e9;
        int n=values.size();
        for(int i=n-1;i>=0;i--){
            int curr=values[i]-i;
            int val=values[i]+i;
            if(pq.size()>0){
                ans=max(ans,pq.top()+val);
            }
            pq.push(curr);
        }
        return ans;
    }
};