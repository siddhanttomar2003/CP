class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void dfs(vector<vector<int>>&vis,vector<vector<int>>&h,int r, int c){
        vis[r][c]=1;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        int n=h.size(),m=h[0].size();
        for(int k=0;k<4;k++){
            int n_r=r+delRow[k];
            int n_c=c+delCol[k];
            if(isValid(n_r,n_c,n,m) && h[n_r][n_c]>=h[r][c] && !vis[n_r][n_c]){
                dfs(vis,h,n_r,n_c);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>vis1(n,vector<int>(m,0)),vis2(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
             dfs(vis1,heights,i,0);
             dfs(vis2,heights,i,m-1);
        }
        for(int j=0;j<m;j++){
            dfs(vis1,heights,0,j);
            dfs(vis2,heights,n-1,j);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] && vis2[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};