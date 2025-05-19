#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> p(n+1), inv(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        inv[p[i]] = i;
    }

    // compute initial number of "breaks"
    int breaks = 0;
    for(int v = 2; v <= n; v++){
        if(inv[v] < inv[v-1]) 
            breaks++;
    }

    auto adjust = [&](int u, int v, int delta){
        // if pair (u,v) is in [2..n], we check if inv[v] < inv[u]
        if(u >= 1 && v >= 2 && v <= n && u == v-1){
            if(inv[v] < inv[u]) 
                breaks += delta;
        }
    };

    while(m--){
        int a, b;
        cin >> a >> b;
        int x = p[a], y = p[b];

        // collect affected pairs (u,v) = (v-1,v)
        vector<pair<int,int>> pairs;
        for(int v : {x, y}){
            pairs.emplace_back(v-1, v);
            pairs.emplace_back(v, v+1);
        }

        // remove duplicates
        sort(pairs.begin(), pairs.end());
        pairs.erase(unique(pairs.begin(), pairs.end()), pairs.end());

        // undo their contribution
        for(auto [u,v] : pairs){
            adjust(u, v, -1);
        }

        // perform the swap in both p[] and inv[]
        swap(p[a], p[b]);
        swap(inv[x], inv[y]);

        // re-apply their contribution
        for(auto [u,v] : pairs){
            adjust(u, v, +1);
        }

        // answer is breaks+1
        cout << breaks + 1 << "\n";
    }

    return 0;
}
