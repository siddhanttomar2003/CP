class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>t(n,vector<int>(m,1e9));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                     q.push({i,j,0});
                     t[i][j]=0;
                }
            }
        }
        while(q.size()>0){
            auto it=q.front();q.pop();
            int r=it[0],c=it[1],steps=it[2];
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int n_r=r+delRow[k];
                int n_c=c+delCol[k];
                if(isValid(n_r,n_c,n,m) && grid[n_r][n_c]==1){
                     grid[n_r][n_c]=2;
                     t[n_r][n_c]=steps+1;
                     q.push({n_r,n_c,steps+1});
                }
            }
        }
        int mini=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                if(grid[i][j]!=0){
                mini=max(mini,t[i][j]);
                }
            }
        }
        return mini;
    }
};
