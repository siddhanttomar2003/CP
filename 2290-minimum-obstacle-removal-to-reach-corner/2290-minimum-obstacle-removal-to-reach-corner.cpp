typedef pair<int,int> pii;
typedef pair<int,pii>  ppi;
class Solution {
public:
    bool check(int i, int j, int n, int m ){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(pq.size()>0){
            int dis_c=pq.top().first;
            int curr_x=pq.top().second.first;
            int curr_y=pq.top().second.second;
            pq.pop();
            int delRow[]={1,0,-1,0};
            int delCol[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int n_r=curr_x+delRow[i];
                int n_c=curr_y+delCol[i];
                if(check(n_r,n_c,n,m)){
                    int wt=grid[n_r][n_c];
                    if(dis[n_r][n_c] > wt+dis[curr_x][curr_y]){
                        dis[n_r][n_c]=wt+dis[curr_x][curr_y];
                        pq.push({dis[n_r][n_c],{n_r,n_c}});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<dis[i][j]<<" ";
            cout<<endl;
        }
        return dis[n-1][m-1];
    }
};