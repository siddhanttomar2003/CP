class Solution {
public:
    void build(vector<vector<int>>&ans,int sr, int sc, int er, int ec, int &num){
      if(sr==er && sc==ec){
        ans[sr][sc]=num;
        num--;
        return;
      }
      if(sr>=er || sc>=ec)return;
      int mid_i = (sr+er)/2;
      int mid_j=  (sc+ec)/2;
      build(ans,sr,sc,mid_i,mid_j,num);
      build(ans,mid_i+1,sc,er,mid_j,num);
      build(ans,mid_i+1,mid_j+1,er,ec,num);
      build(ans,sr,mid_j+1,mid_i,ec,num);
    }
    vector<vector<int>> specialGrid(int N) {
        int n=pow(2,N);
        vector<vector<int>>ans(n,vector<int>(n));
        int start=pow(2,2*N)-1;
        build(ans,0,0,n-1,n-1,start);
        return ans;
    }
};