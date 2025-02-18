#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll sum;
    bool assigned;
};

vector<Node> seg;
vector<ll> arr;

void buildTree(int idx, int l, int r) {
    if (l == r) {
        seg[idx].sum = arr[l];
        seg[idx].assigned = false;
        return;
    }
    int mid = (l + r) / 2;
    buildTree(idx * 2, l, mid);
    buildTree(idx * 2 + 1, mid + 1, r);
    seg[idx].sum = seg[idx * 2].sum + seg[idx * 2 + 1].sum;
}

void updateTree(int idx, int l, int r, int pos, ll value) {
    if (l == r) {
        seg[idx].sum = value;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) 
        updateTree(idx * 2, l, mid, pos, value);
    else 
        updateTree(idx * 2 + 1, mid + 1, r, pos, value);
    seg[idx].sum = seg[idx * 2].sum + seg[idx * 2 + 1].sum;
}

ll queryTree(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg[idx].sum;
    }
    if (r < ql || l > qr) return 0;
    int mid = (l + r) / 2;
    return queryTree(idx * 2, l, mid, ql, qr) + queryTree(idx * 2 + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        arr.resize(N);
        seg.assign(4 * N, {0, false});

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        buildTree(1, 0, N - 1);
        while (Q--) {
            int type;
            cin >> type;
            if (type == 1) { 
                int pos;
                ll value;
                cin >> pos >> value;
                updateTree(1, 0, N - 1, pos, value);
            } else if (type == 2) { 
                int l, r;
                cin >> l >> r;
                cout << queryTree(1, 0, N - 1, l, r) << "\n";
            }
        }
    }
    return 0;
}
