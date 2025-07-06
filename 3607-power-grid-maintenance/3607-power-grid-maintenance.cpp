class Dsu {
    public :
    vector<int>parent,size;
    Dsu(int n){
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(),parent.end(), 0);
    }
    int find_par(int node){
        if(parent[node] == node)return node;
        else return parent[node] = find_par(parent[node]);
    }
    void unions(int u, int v){
        u = find_par(u);
        v = find_par(v);
        if(u == v)return;
        if(size[u] > size[v]){
            size[u] += size[v];
            parent[v] = u;
        }
        else {
            size[v] += size[u];
            parent[u] = v;
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        Dsu d(c + 1);
        for(auto it : connections){
            d.unions(it[0], it[1]);
        }
        vector<int>ans;
        unordered_map<int,set<int>>pars;
        for(int i = 1; i <= c; i++){
            pars[d.find_par(i)].insert(i);
        }
        for(auto it:queries){
            if(it[0] == 2){
                int par = d.find_par(it[1]);
                pars[par].erase(it[1]);
                // cout << par << " " << it[1] << endl;
            //       for(auto it : pars){
            // cout << it.first << " ->";
            // for(auto it2 : it.second)cout << it2 << " ";
            // cout << endl;
        
            }
            else {
                int par = d.find_par(it[1]);
                // cout << par << endl;
                if(pars[par].find(it[1]) != pars[par].end()) ans.push_back(it[1]);
                else {
                    if(pars[par].size() == 0)ans.push_back(-1);
                    else ans.push_back(*pars[par].begin());
                }
            }
        }
        return ans;
    }
};