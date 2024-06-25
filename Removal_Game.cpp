#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

// Global memoization table
vvl dp;

ll maxScore(const vl& x, int left, int right) {
    // Base case
    if (left > right) return 0;
    // Memoization check
    if (dp[left][right] != -1) return dp[left][right];
    
    // Option 1: First player picks x[left]
    ll pickLeft = x[left] + min(maxScore(x, left + 2, right), maxScore(x, left + 1, right - 1));
    
    // Option 2: First player picks x[right]
    ll pickRight = x[right] + min(maxScore(x, left + 1, right - 1), maxScore(x, left, right - 2));
    
    // Maximum score first player can achieve
    return dp[left][right] = max(pickLeft, pickRight);
}

void solve() {
    int n;
    cin >> n;
    vl x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    // Initialize memoization table
    dp.assign(n, vl(n, -1));
    
    // Calculate and print the maximum score for the first player
    ll maxScoreFirstPlayer = maxScore(x, 0, n - 1);
    cout << maxScoreFirstPlayer << endl;
}

int main() {
    solve();
    return 0;
}
