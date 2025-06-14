class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=grid[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({dis[0][0],0,0});
        while(pq.size()>0){
            int curr=pq.top()[0];
            int curr_r=pq.top()[1];
            int curr_c=pq.top()[2];
            pq.pop();
            int delRow[]={-1,0,1,0};
            int delCol[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int n_r=curr_r+delRow[k];
                int n_c=curr_c+delCol[k];
                if(isValid(n_r,n_c,n,m)){
                     if(dis[n_r][n_c]>max(curr,grid[n_r][n_c])){
                        dis[n_r][n_c]=max(curr,grid[n_r][n_c]);
                        pq.push({dis[n_r][n_c],n_r,n_c});
                     }
                     
                }
            }
        }
        return dis[n-1][m-1];
    }
};