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
            // cout<<v[i][j]<<" ";
        }
        // cout<<endl;
    }
    int s;cin>>s;
    for(int i=0;i<s;i++){
        int a,b;cin>>a>>b;
        int color=grid[a][b];
        grid[a][b]=0;
        // left upper;
        if(a-1>=0 && b-1>=0 && grid[a-1][b-1]==color)grid[a-1][b-1]=0;
        // right upper
        if(a-1>=0 && b+1<m && grid[a-1][b+1]==color)grid[a-1][b+1]=0;
        // left down
        if(a+1<n && b-1>=0 && grid[a+1][b-1]==color)grid[a+1][b-1]=0;
        // right down
        if(a+1<n && b+1<m && grid[a+1][b+1]==color)grid[a+1][b+1]=0;
        form_newgrid(grid,n,m);

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


return 0;
}