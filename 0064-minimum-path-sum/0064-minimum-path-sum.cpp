class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1)return grid[0][0];
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        int delRow[]={0,1};
        int delCol[]={1,0};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int curr_dis=it[0];
            int curr_r=it[1],curr_c=it[2];
            for(int i=0;i<2;i++){
                int n_r=curr_r+delRow[i];
                int n_c=curr_c+delCol[i];
                if(n_r>=0 && n_r<n && n_c>=0 && n_c<m && dis[n_r][n_c]>curr_dis+grid[n_r][n_c]){
                    dis[n_r][n_c]=curr_dis+grid[n_r][n_c];
                    pq.push({dis[n_r][n_c],n_r,n_c});
                }
            }
        }
        return dis[n-1][m-1];
    }
};