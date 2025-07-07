class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
       int count = 0;
       sort(events.begin(), events.end());
       priority_queue<int,vector<int>,greater<int>>pq;
       int n = events.size();
       int day = events[0][0];
       for(int i = 0; i < n; i++){
                while(day < events[i][0] && !pq.empty()){
                   if(pq.top() < day)pq.pop();
                   else {
                    day++;
                    count++;
                    pq.pop();
                   }
                }
            if(events[i][1] >= day){
            day = events[i][0];
            pq.push(events[i][1]);
            }
       }
       while(!pq.empty()){
         if(pq.top() >= day){
            day++;
            count++;
         }
         pq.pop();
       }
       return count;
    }
};