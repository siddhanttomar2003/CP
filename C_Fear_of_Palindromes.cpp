#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[2001][2001][2];

int find_max(string &text1, string &text2, int index1, int index2, int pos1, int pos2, int s) {
    if (index1 == text1.size() || index2 == text2.size()) return 0;

    if (dp[index1][index2][s] != -1) return dp[index1][index2][s];

    int take = 0;
    if (text1[index1] == text2[index2]) {
        if (s == 1) {
            take = 1 + find_max(text1, text2, index1 + 1, index2 + 1, pos1, pos2, 1);
        } else if (index1 < pos1 && index2 < pos2) {
            take = 1 + find_max(text1, text2, index1, index2, pos1, pos2, 1);
        }
    }
    
    int nottake1 = find_max(text1, text2, index1 + 1, index2, pos1, pos2, s);
    int nottake2 = find_max(text1, text2, index1, index2 + 1, pos1, pos2, s);
    
    return dp[index1][index2][s] = max(take, max(nottake1, nottake2));
}

void solve() {
    string x, y;
    cin >> x >> y;
    string f = x + y;
    string t = f;
    reverse(t.begin(), t.end());
    memset(dp, -1, sizeof(dp));
    
    int pos1 = x.size();
    int pos2= y.size();
    int result = find_max(f, t, 0, 0, pos1,pos2,0);
    
    int maxi = 0;
    for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j < f.size(); j++) {
            if (dp[i][j][1] != -1) {
                maxi = max(maxi, dp[i][j][1]);
            }
        }
    }
    if (maxi == 1) maxi = 0;
    cout << maxi << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
