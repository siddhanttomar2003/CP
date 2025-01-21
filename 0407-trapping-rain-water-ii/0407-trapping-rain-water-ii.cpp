class Solution {
public:
    bool check(int cx,int cy, int n, int m){
        if(cx>=0 && cy>=0 && cx<n && cy<m)return true;
        return false;
    }
    int trapRainWater(vector<vector<int>>& h) {
        int ans=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=h.size();int m=h[0].size();
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({h[i][j],i,j});
                    mp[{i,j}]++;
                }
            }
        }
        while(pq.size()>0){
            int curr=pq.top()[0];
            int curr_x=pq.top()[1];
            int curr_y=pq.top()[2];
            pq.pop();
            // mp[{curr_x,curr_y}]++;
            int delRow[]={1,0,-1,0};
            int delCol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nx=curr_x+delRow[i];
                int ny=curr_y+delCol[i];
                if(check(nx,ny,n,m) && mp.find({nx,ny})==mp.end()){
                    ans+=max(curr-h[nx][ny],0);
                    mp[{nx,ny}]++;
                    pq.push({max(curr,h[nx][ny]),nx,ny});
                }
            }
        }
        
        return ans;
    }
};