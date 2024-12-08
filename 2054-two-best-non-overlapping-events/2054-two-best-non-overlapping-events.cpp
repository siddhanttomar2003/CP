class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=events.size();
        sort(events.begin(),events.end());
        int ans=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int wt=events[i][2];
            int start=events[i][0];
            int end=events[i][1];
            while(pq.size()>0  &&  start>pq.top().first){
                maxi=max(maxi,pq.top().second);
                ans=max(ans,wt+maxi);
                pq.pop();
            }
            ans=max(ans,wt+maxi);
            pq.push({end,wt});
        }
        while(pq.size()>0){
            ans=max(ans,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};