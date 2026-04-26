class Dsu {
    public :
    vector<int>par, size;
    Dsu(int n){
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        size.resize(n, 1);
    }
    int find_par(int u){
        if(par[u] == u)return u;
        else return par[u] = find_par(par[u]);
    }
    void unions(int u, int v){
        u = find_par(u);
        v = find_par(v);
        if(u == v)return;
        if(size[u] > size[v]){
            size[u] += size[v];
            par[v] = u;
            size[v] = 0;
        }
        else {
            size[v] += size[u];
            par[u] = v;
            size[u] = 0;
        }
    }
};
class Solution {
public:
    bool check(unordered_set<int>&st, vector<int>&nums, vector<vector<int>>&edges){
        int n = nums.size();
        int sum = 0;
        Dsu d(n);
        for(auto it : edges){
            int u = it[0], v = it[1];
            if(st.find(u) != st.end() && st.find(v) != st.end() && d.find_par(u) != d.find_par(v)){
                d.unions(u, v);
            }
        }
        int s = 0;
        for(int i = 0; i < n; i++){
           if(st.find(i) != st.end() && d.size[i]){
                s++;
           }
           if(st.find(i) != st.end())sum += nums[i];
        }
        return s == 1 && sum % 2 == 0;
    }
    int build_nodes(vector<vector<int>>&adj, vector<int>&nums, int m, int i, unordered_set<int>&curr){
        if(i == m){
            if(curr.size() == 0)return 0;
            if(check(curr, nums, adj)){
                return 1;
            }
            return 0;
        }
        curr.insert(i);
        int w1 = build_nodes(adj, nums, m, i + 1, curr);
        curr.erase(i);
        int w2 = build_nodes(adj, nums, m, i + 1, curr);
        return w1 + w2;
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int m = edges.size();
        unordered_set<int>vis;
        return build_nodes(edges, nums, n, 0, vis);
    }
};