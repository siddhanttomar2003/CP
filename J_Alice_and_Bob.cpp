#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Line {
    ll m, b;
    Line(ll _m = 0, ll _b = LLONG_MAX) : m(_m), b(_b) {}
    ll get(ll x) const { return m * x + b; }
};
struct LiChao {
    struct Node {
        Line line;
        Node* left;
        Node* right;
        Node(Line l) : line(l), left(nullptr), right(nullptr) {}
    };
    Node* root;
    ll L, R;
    LiChao(ll _L, ll _R) : L(_L), R(_R) { root = new Node(Line(0, LLONG_MAX)); }
    void add_line(Line newline) { add_line(root, L, R, newline); }
    void add_line(Node* node, ll l, ll r, Line newline) {
        ll mid = (l + r) >> 1;
        bool leftBetter = newline.get(l) < node->line.get(l);
        bool midBetter  = newline.get(mid) < node->line.get(mid);
        if(midBetter) swap(node->line, newline);
        if(r - l == 1) return;
        if(leftBetter != midBetter) {
            if(!node->left) node->left = new Node(Line(0, LLONG_MAX));
            add_line(node->left, l, mid, newline);
        } else {
            if(!node->right) node->right = new Node(Line(0, LLONG_MAX));
            add_line(node->right, mid, r, newline);
        }
    }
    ll query(ll x) { return query(root, L, R, x); }
    ll query(Node* node, ll l, ll r, ll x) {
        if(!node) return LLONG_MAX;
        ll mid = (l + r) >> 1;
        ll ans = node->line.get(x);
        if(r - l == 1) return ans;
        if(x < mid)
            ans = min(ans, query(node->left, l, mid, x));
        else
            ans = min(ans, query(node->right, mid, r, x));
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<ll> dp(n+1, 0);
    dp[0] = 0;
    ll X_MAX = 1000000005;
    LiChao tree(0, X_MAX);
    tree.add_line(Line(0, 0));
    for (int i = 1; i <= n; i++){
        ll X = a[i] + 1;
        ll best = tree.query(X);
        dp[i] = i * X - 1 + best;
        tree.add_line(Line(-i, dp[i]));
    }
    cout << dp[n] << "\n";
    return 0;
}
