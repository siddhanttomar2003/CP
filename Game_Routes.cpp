#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define inll(x) long long int x; cin >> x;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

void solve() {
    inll(n); inll(m);
    vector<vector<ll>> adj(n + 1);
    vector<ll> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        inll(u); inll(v);
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<ll> q;
    vl ways(n + 1, 0);

    // Start from node 1
    ways[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u]) {
            ways[v] += ways[u];
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << ways[n] << endl;
}

int32_t main() {
    fastio();
    solve();
    return 0;
}
