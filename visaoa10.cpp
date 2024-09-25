#include<bits/stdc++.h>
using namespace std;

void form_newgrid(vector<vector<int>> & grid, int n, int m){
    for(int j=0;j<m;j++){
     for(int i=n-1;i>=0;i--){
        if(grid[i][j]!=0){
            int k=i+1;
            while(k<n && grid[k][j]==0){
                k++;
            }
            k--;
            int color=grid[i][j];
            grid[i][j]=0;
            grid[k][j]=color;
        }
     }
    }
}
int main()
{
 int n,m;cin>>n>>m;
 vector<vector<int>>grid(n,vector<int>(m));
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
 }
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        int color=grid[i][j];
        int c=0;
        for(int k=0;k<4;k++){
            int nr=i+delRow[k];
            int nc=j+delCol[k];
            if(valid(nr,nc,n,m) && grid[nr][nc]==color ){
              c++;
            }
        }
        if(c>=2){
              for(int k=0;k<4;k++){
            int nr=i+delRow[k];
            int nc=j+delCol[k];
            if(valid(nr,nc,n,m) && grid[nr][nc]==color ){
               grid[nr][nc]=0;
            }
        }
        }

    }
 }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<endl;
   }

return 0;
}