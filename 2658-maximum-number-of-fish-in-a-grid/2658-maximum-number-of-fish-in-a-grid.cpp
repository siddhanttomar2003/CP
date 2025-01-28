class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>&grid,map<pair<int,int>,int>&mp, int n, int m){
        queue<pair<int,int>>q;
        q.push({i,j});
        mp[{i,j}]++;
        int ans=0;
        while(q.size()>0){
         int c_r=q.front().first;
         int c_c=q.front().second;
         q.pop();
         ans+=grid[c_r][c_c];
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=c_r+delRow[k];
            int nc=c_c+delCol[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]!=0 && mp.find({nr,nc})==mp.end()){
                  mp[{nr,nc}]++;
                  q.push({nr,nc});
            }
        }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<pair<int,int>,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && mp.find({i,j})==mp.end()){
                    ans=max(ans,bfs(i,j,grid,mp,n,m));
                }
            }
        }
        return ans;
    }
};