class Dsu {
   public:
   vector<int>parent,size;
   Dsu(int n){
    parent.resize(n+1);
    iota(parent.begin(),parent.end(),0);
    size.resize(n+1,1);
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        Dsu d(n);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 int wt=abs(points[j][1]-points[i][1])+abs(points[j][0]-points[i][0]);
                 pq.push({wt,i,j});
            }
        }
        int sum=0;
        while(pq.size()>0){
            int u=pq.top()[1];
            int v=pq.top()[2];
            int wt=pq.top()[0];
            if(d.find_par(u)!=d.find_par(v)){
                sum+=wt;
                d.unions(u,v);
            }
            pq.pop();
        }
        return sum;
    }
};