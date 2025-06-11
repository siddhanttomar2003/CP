class Dsu{
    public:
    vector<int>size,parent;
    Dsu(int n){
      size.resize(n+1,1);
      parent.resize(n+1);
      for(int i=0;i<=n;i++){
        parent[i]=i;
      }
    }
    int find_par(int node){
        if(parent[node]==node)return node;
        return parent[node]=find_par(parent[node]);
    }
    void unions(int u, int v){
        u=find_par(u);
        v=find_par(v);
        if(u==v)return;
        if(size[u]<size[v]){
            size[v]+=size[u];
            size[u]=0;
            parent[u]=v;
        }
        else {
            size[u]+=size[v];
            size[v]=0;
            parent[v]=u;
        }
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        Dsu d(n*m);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                count++;
                int number=i*m+j;
                   if(i-1>=0 && grid[i-1][j]==1){
                       int num=(i-1)*m+j;
                       d.unions(number,num);
                   }
                   if(i+1<n && grid[i+1][j]==1){
                       int num=(i+1)*m+j;
                       d.unions(number,num);
                   }
                   if(j-1>=0 && grid[i][j-1]==1){
                       d.unions(number,number-1);
                   }
                   if(j+1<m && grid[i][j+1]==1){
                       d.unions(number,number+1);
                   }
                }
            }
        }
        int max_area=0;
        for(int i=0;i<n*m;i++){
                int r=i/m;
                int c=i%m;
                // cout<<r<<" "<<c<<endl;
                if(grid[r][c]){
                max_area=max(max_area,d.size[i]);
                }
            // cout<<d.size[i]<<" ";
        }
        return max_area;
    }
};
