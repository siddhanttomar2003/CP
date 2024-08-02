// author:-Siddhant Tomar
// linked in :-https://www.linkedin.com/in/siddhant-tomar-9b3aab261/

#include <bits/stdc++.h>
using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Macros
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl
#define pe cout << endl

// Typedef
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

// Operator overloads
template<typename T>
istream& operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) cin >> it;
    return istream;
}

template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &v) {
    for (const auto &it : v) cout << it << " ";
    return ostream;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    set<pll> st;
    st.insert({1, 1});
    
    vector<ll> parent(n + 1);
    vector<ll> dis(n + 1, 0);  // Initialize distances with 0 indicating unvisited
    for (ll i = 1; i <= n; ++i) parent[i] = i;

    while (!st.empty()) {
        ll dist = st.rbegin()->first;
        ll par = st.rbegin()->second;
        st.erase(prev(st.end()));

        if (dist < dis[par]) continue;

        for (ll child : adj[par]) {
            if (dis[child] < dist + 1) {
                parent[child] = par;
                dis[child] = dist + 1;
                st.insert({dis[child], child});
            }
        }
    }

    if (dis[n] == 0) {  // Check if the node is unvisited
        out("IMPOSSIBLE");
        return;
    }

    out(dis[n]);
    ll s = n;
    vector<ll> path;
    while (parent[s] != s) {
        path.push_back(s);
        s = parent[s];
    }
    path.push_back(1);
    reverse(all(path));
    cout << path << " ";
    pe;
}

int32_t main() {
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    solve();

    return 0;
}
