class Dsu{
    public:
    vector<int>parent,size;
    Dsu(int n){
        size.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int start=-1;
        vector<vector<int>>seg;
        seg.push_back({0});
        for(int i=0;i<n-1;i++){
            if(i+1<n && nums[i+1]-nums[i]<=maxDiff){
                seg.back().push_back(i+1);
            }
            else seg.push_back({i+1});
        }
        Dsu d(n);
        for(auto it:seg){
            for(int i=0;i<it.size()-1;i++){
                d.unions(it[i],it[i+1]);
            }
        }
        vector<bool>ans;
        for(auto it:queries){
            if(d.find_par(it[0])==d.find_par(it[1]))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;

    }
};