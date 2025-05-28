class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    dis[i][j]=0;
                    q.push({0,i,j});
                }
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int curr_r=q.front()[1];
            int curr_c=q.front()[2];
            int curr_dis=q.front()[0];
            q.pop();
            for(int i=0;i<4;i++){
                int n_r=curr_r+delRow[i];
                int n_c=curr_c+delCol[i];
                if(n_r>=0 && n_r<n && n_c>=0 && n_c<m && dis[n_r][n_c]>curr_dis+1){
                    dis[n_r][n_c]=curr_dis+1;
                    q.push({curr_dis+1,n_r,n_c});
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 maxi=max(maxi,dis[i][j]);
            }
        }
        if(maxi==0)return -1;
        return maxi;
    }
};