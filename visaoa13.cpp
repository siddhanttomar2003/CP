#include<bits/stdc++.h>
using namespace std;

int cal(vector<vector<int>>&grid, int i, int j, int n, int m){
    int sr=i;
    int sc=j;
    int c1=0;
    // upper diagonal
    while(  sr>=0 && sc<m  &&  grid[sr][sc] ){
        c1++;
        sr--;sc++;
    }
    // lower diagonal
    sr=i;sc=j;int c2=0;
    while(sr<n && sc>=0 && grid[sr][sc]){
        c2++;
        sr++;sc--;
    }
    // left upper
    sr=i;sc=j;int c3=0;
    while(sr>=0 && sc>=0 && grid[sr][sc]){
         c3++;
         sr--;sc--;
    }
    // right lower
    sr=i;sc=j;int c4=0;
    while(sr<n && sc<m && grid[sr][sc]){
        c4++;
        sr++;sc++;
    }
    return min({c1,c2,c3,c4});


}
int main()
{

int n,m;cin>>n>>m;
vector<vector<int>>grid(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
        // cout<<grid[i][j]<<" ";
    }
    // cout<<endl;
}
 int ans=0;
 pair<int,int>f_ans;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]){
          int curr=cal(grid,i,j,n,m);
          if(curr>ans){
            ans=curr;
            f_ans={i,j};
          }
        }
    }
 }
 cout<<f_ans.first<<" "<<f_ans.second<<endl;

return 0;
}