class Dsu{
  public:
  vector<int>parent,size;
  Dsu(int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    iota(parent.begin(),parent.end(),0);
  }
  int find_par(int node){
    if(parent[node]==node)return node;
    else return parent[node]=find_par(parent[node]);
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
    vector<bool>is_prime;
   
    void Sieve(int n,unordered_set<int>&st, Dsu &d){
        is_prime.resize(n+1,true);
        is_prime[0]=is_prime[1]=false;
        for(int i=2;i<=n;i++){
            if(is_prime[i]){
                for(int j=2*i;j<=n;j+=i){
                    if(st.find(j)!=st.end()){
                          d.unions(i,j);
                    }
                    is_prime[j]=false;
                }
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        for(auto it:nums){
            if(it==1)return false;
        }
        unordered_set<int>st(nums.begin(),nums.end());
        Dsu d(1e5);
        Sieve(1e5,st,d);
        int maxi=*max_element(nums.begin(),nums.end());
        int par=d.find_par(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(par!=d.find_par(nums[i]))return false;
        }
        return true;
    }
};