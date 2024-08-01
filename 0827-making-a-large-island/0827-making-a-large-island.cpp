class Solution {
public:
    class Dsu{
        public:
     vector<int>parent;
     vector<int>size;
     Dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
     }
     int findparent(int node){
        if(parent[node]==node)return node;
        else return parent[node]=findparent(parent[node]);
     }
     void unionbySize(int u, int v){
        u=findparent(u);
        v=findparent(v);
        if(u==v)return;
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }
        else {
            parent[u]=v;
            size[v]+=size[u];
        }
     }

    };
    int largestIsland(vector<vector<int>>& grid) {
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
       
         int maxi=0;
        int n=grid.size();int m=grid[0].size();
         Dsu d(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr=n*i+j;
                if(grid[i][j]==1){
                for(int k=0;k<4;k++){
                    int nr=i+delRow[k];
                    int nc=j+delCol[k];
                    int child=nr*n+nc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                          d.unionbySize(curr,child);
                    }
                }
            }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr=i*n+j;
                maxi=max(maxi,d.size[d.parent[curr]]);
                if(grid[i][j]==0){
                    set<int>st;
                     for(int k=0;k<4;k++){
                    int nr=i+delRow[k];
                    int nc=j+delCol[k];
                    int child=nr*n+nc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        //   d.unionbySize(curr,child);
                        st.insert(d.findparent(child));
                    }
                }
                int temp=0;
                for(auto it:st){
                    temp+=d.size[it];
                }
                temp++;
                maxi=max(maxi,temp);
                }
            }
        }
        return maxi;

    }
};