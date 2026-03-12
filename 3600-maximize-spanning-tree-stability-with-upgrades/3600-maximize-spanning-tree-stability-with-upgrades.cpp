class Solution {
public:
    class Dsu {
        public:
        vector<int>size, parent;
        Dsu(int n){
            size.resize(n, 1);
            parent.resize(n, 0);
            for(int i = 0; i < n; i++)parent[i] = i;
        }
        int find_par(int node){
            if(parent[node] == node)return node;
            else return parent[node] = find_par(parent[node]);
        }
        void unions(int u, int v){
            u = find_par(u);
            v = find_par(v);
            if(u == v)return;
            if(size[u] < size[v]){
                size[v] += size[u];
                parent[u] = v;
                size[u] = 0;
            }
            else {
                size[u] += size[v];
                parent[v] = u;
                size[v] = 0;
            }
        }
    };
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
            return a[2] > b[2];
        });
        int size = edges.size();
        if(size < n - 1)return -1;
        int use = 0;
        int must = 0;
        int curr_mini = 1e9;
        Dsu d(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int m = it[3];
            if(m){
                d.unions(u, v);
                curr_mini = min(curr_mini, s);
                must++;
                use++;
            }
        }
        if(must >= n)return -1;
        vector<int>req;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int m = it[3];
            if(!m && d.find_par(u) != d.find_par(v)){
                d.unions(u, v);
                use++;
                req.push_back(s);
            }
        }
        if(use != n - 1)return -1;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(d.size[i] > 0)count++;
        }
        if(count > 1)return -1;
        if(req.size()){
            sort(req.begin(), req.end());
            for(int i = 0; i < min(k , (int)req.size()); i++){
                req[i] = req[i] * 2;
            }
            int mini = *min_element(req.begin(), req.end());
            return min(curr_mini, mini);
        }
        return curr_mini;
    }
};