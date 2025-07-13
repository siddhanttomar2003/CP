class Dsu {
    public : 
    vector<int>parent,size;
    Dsu(int n){
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find_par(int node){
        if(parent[node] == node)return node;
        else return parent[node] = find_par(parent[node]);
    }
    void unions(int u, int v){
        u = find_par(u);
        v = find_par(v);
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
    vector<vector<int>>ed;
    bool check(int mid, int k, int n){
        Dsu d(n);
        int count = 0;
        for(auto it : ed){
            if(it[2] <= mid){
                int u = it[0];
                int v = it[1];
                if(d.find_par(v) != d.find_par(u)){
                    d.unions(u, v);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(d.size[i] != 0)count++;
        }
        return count <= k;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int low = 0;
        int high = 0;
        for(auto &it : edges){
            high = max(high, it[2]);
        }
        ed = edges;
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, k, n)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};