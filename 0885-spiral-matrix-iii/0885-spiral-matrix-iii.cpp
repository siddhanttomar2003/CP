class Solution {
public:
    bool check(int r, int c, int n , int m){
        return r>=0 && r<n && c<m && c>=0;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int steps=1;
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        int size_req=rows*cols;
        int curr_dir=0;
        while(ans.size()<size_req){
           int curr_steps=steps;
           while(curr_steps--){
              int n_r=dir[curr_dir].first+rStart;
              int n_c=dir[curr_dir].second+cStart;
              if(check(n_r,n_c,rows,cols)){
                 ans.push_back({n_r,n_c});
              }
              rStart=n_r;
              cStart=n_c;
           }
           curr_dir=(curr_dir+1)%4;
           if(curr_dir==2 || curr_dir==0)steps++;
        }
        return ans;
    }
};