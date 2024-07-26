#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Disjoint{
vector<int>parent;
vector<int>rank;
public:
Disjoint(int n){
    parent.resize(n+1);
    rank.resize(n+1,0);
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
      else if(rank[u]<rank[v]){
        parent[u]=v;
      }
      else if(rank[v]<rank[u]){
        parent[v]=u;
      }
      else{
        parent[u]=v;
        rank[v]++;
      }
}
};

int main()
{
Disjoint d(7);
d.unions(1,2);
d.unions(2,3);
d.unions(4,5);
d.unions(6,7);
d.unions(5,6);
// d.union(1,2);
if(d.findpar(3)==d.findpar(7))cout<<"same"<<endl;
else cout<<"NOt Same"<<endl;
d.unions(3,7);
if(d.findpar(3)==d.findpar(7))cout<<"same"<<endl;
else cout<<"NOt Same"<<endl;
return 0;
}