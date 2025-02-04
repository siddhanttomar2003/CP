#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to check if we can run M applications for at least T minutes
bool isPossible(vector<ll>& apis, ll M, ll T) {
    ll appCount = 0; // Tracks how many applications we can run for at least T minutes

    for (ll runtime : apis) {
        appCount += (runtime / T); // Each API can contribute `runtime / T` full application runs
        if (appCount >= M) return true; // If we already have enough applications, return true
    }
    
    return false; // Not enough applications can be run for T minutes
}

void solve() {
    int N;
    cin >> N;
    
    vector<ll> apis;
    ll total_api_time = 0;
    
    for (int i = 0; i < N; i++) {
        ll runtime;
        cin >> runtime;
        if (runtime != -1) {  // Ignore invalid API runtimes
            apis.push_back(runtime);
            total_api_time += runtime;  // Track the total available API time
        }
    }

    int M;
    cin >> M;

    if (apis.empty()) {
        cout << "0\n"; // If there are no valid APIs, return 0
        return;
    }

    // Binary search on maximum possible T
    ll low = 0, high = total_api_time, ans = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (isPossible(apis, M, mid)) {
            ans = mid;  // If we can run M applications for at least mid minutes, store result
            low = mid + 1; // Try for a larger value of T
        } else {
            high = mid - 1; // Reduce T if it's not possible
        }
    }

    cout << ans << "\n"; // Print the maximum time applications can run simultaneously
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
