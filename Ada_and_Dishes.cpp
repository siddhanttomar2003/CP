#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    std::cin >> n;
    int c[n];
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    sort(c, c+n, greater<int>());
    int ans = 0, var = 0;
    for (int i = 0; i < n; i++) {
        if(var<ans){
            var += c[i];
        }
        else ans += c[i];
    }
    std::cout << max(var, ans) << std::endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
	    solve();
	}
	return 0;
}