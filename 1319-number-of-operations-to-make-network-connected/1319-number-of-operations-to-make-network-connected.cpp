
struct Disjoint{
// public:
vector<int>parent;
vector<int>ran;
Disjoint(int n){

    parent.resize(n+1);
    ran.resize(n+1,0);
    for(int i=0;i<n+1;i++){
        parent[i]=i;
    }
}
int findpar(int node){
    if(parent[node]==node)return node;
    else return parent[node]=findpar(parent[node]);
}
public:
void unions(int u, int v){
      u=findpar(u);
      v=findpar(v);
      if(u==v)return;
      else if(ran[u]<ran[v]){
        parent[u]=v;
      }
      else if(ran[v]<ran[u]){
        parent[v]=u;
      }
      else{
        parent[u]=v;
        ran[v]++;
      }
}
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edge=connections.size();
        if(edge<n-1)return -1;
        int ans=0;
        Disjoint d(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
              d.unions(u,v);
        }
        int maxi=0;
        int maxi_rank=0;
        vector<int>temp=d.ran;
        for(int i=0;i<n;i++){
             if(temp[i]>maxi){
                maxi=temp[i];
                maxi_rank=i;
             }
        }
        for(int i=0;i<n;i++){
            if(d.findpar(i)!=d.findpar(maxi_rank)){
                ans++;
                d.unions(i,maxi_rank);
            }
        }
        return ans;
        
    }
};