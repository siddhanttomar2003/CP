class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        map<pair<int,int>,int>mp;
        int n=moveTime.size();int m=moveTime[0].size();
        vector<vector<long long>>reach(n,vector<long long>(m,1e10));
       priority_queue<pair<long long, pair<long long, pair<int, int>>>, 
                       vector<pair<long long, pair<long long, pair<int, int>>>>, 
                       greater<pair<long long, pair<long long, pair<int, int>>>>> pq;

        reach[0][0] = 0;
        pq.push({0, {0, {0, 0}}});  // {time, {steps, {row, col}}}
        reach[0][0]=0;
        mp[{0,0}]++;
        while(pq.size()>0){
            long long curr_time=pq.top().first;
            int i=pq.top().second.second.first;
            int j=pq.top().second.second.second;
            long long steps=pq.top().second.first;

            pq.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int nr=i+delRow[k];
                int nc=j+delCol[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && mp.find({nr,nc})==mp.end()){
                   mp[{nr,nc}]++;
                   long long add=0;
                   if(steps&1){
                    add=2;
                   }
                   else {
                    add=1;
                   }
                    reach[nr][nc]=min(reach[nr][nc],max(curr_time+add,moveTime[nr][nc]*1ll+add));
                    pq.push({reach[nr][nc],{steps+1,{nr,nc}}});
                }
            }
        }
 
        return reach[n-1][m-1];
        
    }
};