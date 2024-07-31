#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sr, sc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'A') {
                sr = i; sc = j;
                break;
            }
        }
    }
    if(sr==0 || sr==n-1 || sc==0 || sc==m-1){
		cout<<"YES"<<endl;cout<<0<<endl;return;
	}
    // starting positions of all monsters
    map<pair<int, int>, int> lava;
    queue<pair<int, pair<int, int>>> q1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'M') {
                q1.push({0, {i, j}});
                lava[{i, j}] = 0;
            }
        }
    }

    // pushing all monsters and finding their respective times
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};
    while (!q1.empty()) {
        int timer = q1.front().first;
        int i = q1.front().second.first;
        int j = q1.front().second.second;
        q1.pop();
        for (int k = 0; k < 4; k++) {
            int nr = i + delRow[k];
            int nc = j + delCol[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] != '#' && lava.find({nr, nc}) == lava.end()) {
                lava[{nr, nc}] = timer + 1;
                q1.push({timer + 1, {nr, nc}});
            }
        }
    }

    // finding the path
    map<pair<int, int>, pair<int, int>> mp;
    bool flag = false;
    int tr, tc;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {sr, sc}});
    mp[{sr, sc}] = {sr, sc};

    while (!q.empty()) {
        int wt = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = i + delRow[k];
            int nc = j + delCol[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] != '#' && (lava.find({nr, nc}) == lava.end() || lava[{nr, nc}] > wt + 1) && mp.find({nr, nc}) == mp.end()) {
                mp[{nr, nc}] = {i, j};
                if (nr == 0 || nc == 0 || nr == n - 1 || nc == m - 1) {
                    tr = nr; tc = nc;
                    flag = true;
                    break;
                }
                q.push({wt + 1, {nr, nc}});
            }
        }
        if (flag) break;
    }

    if (!flag) {
        cout << "NO" << endl;
    } else {
        string ans = "";
        while (mp[{tr, tc}] != make_pair(tr, tc)) {
            int parentr = mp[{tr, tc}].first;
            int parentc = mp[{tr, tc}].second;
            if (parentr - tr == -1) ans += 'D';
            else if (parentr - tr == 1) ans += 'U';
            if (parentc - tc == -1) ans += 'R';
            else if (parentc - tc == 1) ans += 'L';
            tr = parentr;
            tc = parentc;
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
