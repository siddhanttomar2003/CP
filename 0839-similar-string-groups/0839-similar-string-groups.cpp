class Dsu {
 public:
 vector<int>parent, size;
 Dsu(int n){
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
 }

 int find_par(int node){
    if(parent[node] == node)return node;
    else return parent[node] = find_par(parent[node]);
 }
 void unions(int u, int v)
 {
    u = find_par(u);
    v = find_par(v);
    if(u == v)return ;
    if(size[u] < size[v]){
        size[v] += size[u];
        size[u] = 0;
        parent[u] = v;
    }
    else {
        size[u] += size[v];
        size[v] = 0;
        parent[v] = u;
    }
 }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        Dsu d(n + 1);
        int ans = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            int size1 = strs[i].size();
            for(int  j = i + 1; j < strs.size(); j++){
                int size2 = strs[j].size();
                if(size1 == size2){
                    int count = 0;
                    int k = 0;
                    while(k < strs[i].size()){
                        if(strs[i][k] == strs[j][k])k++;
                        else {
                            count++;
                            k++;
                        }
                    }
                    if(count <= 2){
                        if(d.find_par(i) != d.find_par(j)){
                            d.unions(i, j);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < strs.size(); i++){
            if(d.size[i] > 0)ans++;
        }
        return ans;
    }
};