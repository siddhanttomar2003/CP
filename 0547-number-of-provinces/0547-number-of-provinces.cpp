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
    int findparent(int u){
     if(parent[u]==u)return u;
     else {
        return parent[u]=findparent(parent[u]);
     }
    }
    void unionbysize(int u, int v){
         u=findparent(u);
         v=findparent(v);
         if(u==v)return;
         if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
         }
         else {
            parent[v]=u;
            size[u]+=size[v];
         }
    }


};

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        Dsu d(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    d.unionbysize(i+1,j+1);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(d.parent[i]==i)ans++;
        }
        return ans;
    }
};