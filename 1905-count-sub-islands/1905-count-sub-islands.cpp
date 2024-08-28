class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool &check,int i, int j){
        if(grid1[i][j]==0 && grid2[i][j]==1){
            check=false;return;
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        grid2[i][j]=0;
        for(int k=0;k<4;k++){
            int nr=delRow[k]+i;
            int nc=delCol[k]+j;
            if(nr>=0 && nc>=0 && nr<grid1.size() && nc<grid1[0].size() && grid2[nr][nc]){
                dfs(grid1,grid2, check, nr , nc);
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool check=true;
                if(grid2[i][j]){
                   dfs(grid1,grid2,check,i,j);
                   if(check)
                    ans++;
                }
            }
        }
        return ans;
    }
};