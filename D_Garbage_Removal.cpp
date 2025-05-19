#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N;
    cin >> H >> W >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        --X[i];
        --Y[i];
    }

    vector<vector<int>> inRow(H), inCol(W);
    for (int i = 0; i < N; i++) {
        inRow[X[i]].push_back(i);
        inCol[Y[i]].push_back(i);
    }

    vector<int> rowCnt(H), colCnt(W);
    for (int r = 0; r < H; r++) rowCnt[r] = inRow[r].size();
    for (int c = 0; c < W; c++) colCnt[c] = inCol[c].size();

    vector<bool> removed(N, false);

    int Q;
    cin >> Q;
    while (Q--) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            int x = v - 1;
            cout << rowCnt[x] << "\n";
            for (int pid : inRow[x]) {
                if (!removed[pid]) {
                    removed[pid] = true;
                    colCnt[Y[pid]]--;
                }
            }
            rowCnt[x] = 0;
        } else {
            int y = v - 1;
            cout << colCnt[y] << "\n";
            for (int pid : inCol[y]) {
                if (!removed[pid]) {
                    removed[pid] = true;
                    rowCnt[X[pid]]--;
                }
            }
            colCnt[y] = 0;
        }
    }
    return 0;
}
