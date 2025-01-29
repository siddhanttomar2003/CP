class Dsu{
   public:
   vector<int>parent,size;
   Dsu(int n){
    parent.resize(n);
    size.resize(n,1);
    for(int i=0;i<n;i++)parent[i]=i;
   }
   int findpar(int node){
    if(parent[node]==node)return node;
    else return parent[node]=findpar(parent[node]);
   }
   void unions(int u , int v){
     u=findpar(u);
     v=findpar(v);
     if(u==v)return ;
     if(size[u]<size[v]){
        size[v]+=size[u];
        parent[u]=v;
     }
     else {
        size[u]+=size[v];
        parent[v]=u;
     }
   }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Dsu d(n+1);
         for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(d.findpar(u)==d.findpar(v)){
                return {u,v};
            }
            d.unions(u,v);
         }
         return {0};
    }
};