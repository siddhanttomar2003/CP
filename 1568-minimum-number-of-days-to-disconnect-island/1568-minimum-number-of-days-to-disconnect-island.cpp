class Solution {
public:
   void dfs(int sr, int sc, vector<vector<int>> &grid){
    grid[sr][sc]=0;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    int n=grid.size();int m=grid[0].size();
    for(int i=0;i<4;i++){
        int nr=sr+delRow[i];
        int nc=sc+delCol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]){
            dfs(nr,nc,grid);
        }
    }
   }
    int minDays(vector<vector<int>>& grid) {
        // map<pair<int,int>,int>mp;
        int n=grid.size();int m=grid[0].size();
        int cal=0;
        int count1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])count1++;
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                  if(grid[i][j])count++;
            }
            if(count==count1)flag=true;
        }
        for(int j=0;j<m;j++){
            int count=0;
            for(int i=0;i<n;i++){
                   if(grid[i][j])count++;
            }
            if(count==count1)flag=true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    cal++;
                    dfs(i,j,grid);
                }
            }
        }
        if(cal>1 || cal<1)return 0;
        else {
              if(flag && count1>2)return 1;
              else return 2;
        }
    }
};