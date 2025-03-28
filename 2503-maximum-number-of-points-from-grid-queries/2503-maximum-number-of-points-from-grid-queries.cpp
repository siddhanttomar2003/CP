class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<int>st(queries.begin(),queries.end());
        map<int,int>ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=1;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        int count=0;
        for(auto it:st){
            while(pq.size()>0 && pq.top()[0]<it){
                int x=pq.top()[1],y=pq.top()[2];
                pq.pop();
                count++;
                for(int i=0;i<4;i++){
                    int n_x=x+delRow[i];
                    int n_y=y+delCol[i];
                    if(n_x<n && n_x>=0 && n_y>=0 && n_y<m && !vis[n_x][n_y]){
                        vis[n_x][n_y]=1;
                        pq.push({grid[n_x][n_y],n_x,n_y});
                    }
                }
            }
            ans[it]=count;
        }
        vector<int>f;
        for(auto it:queries){
            f.push_back(ans[it]);
        }
        return f;
    }
};