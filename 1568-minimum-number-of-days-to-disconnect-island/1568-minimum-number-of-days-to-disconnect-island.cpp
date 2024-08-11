class Solution {
public:
   void dfs(int sr, int sc, vector<vector<int>> &grid,map<pair<int,int>,int> &mp){
     mp[{sr,sc}]++;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    int n=grid.size();int m=grid[0].size();
    for(int i=0;i<4;i++){
        int nr=sr+delRow[i];
        int nc=sc+delCol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] && mp.find({nr,nc})==mp.end()){
            dfs(nr,nc,grid,mp);
        }
    }
   }
  
   int check(vector<vector<int>> &grid){
       int n=grid.size();int m=grid[0].size();
       int cal=0;
       map<pair<int,int>,int>mp;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] && mp.find({i,j})==mp.end()){
                cal++;
                dfs(i,j,grid,mp);
            }
        }
       }
       return cal;
   }
    int minDays(vector<vector<int>>& grid) {
        // map<pair<int,int>,int>mp;
        int n=grid.size();int m=grid[0].size();
        int cal=0;
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && mp.find({i,j})==mp.end()){
                    cal++;
                    dfs(i,j,grid,mp);
                }
            }
        }
        if(cal!=1)return 0;
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                     int cc=check(grid);
                     if(cc!=1)return 1;
                     grid[i][j]=1;
                }
            }
        }

      return 2;
    }
};