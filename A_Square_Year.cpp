#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    long long res = 0;

    if (n % 2 == 0) {
        int k = n / 2;
        for (int i = 0; i < k; i++) {
            res += v[n - 1 - i];
        }
        for (int i = 0; i < k; i++) {
            res -= v[i];
        }
    } else {
        int p = (n + 1) / 2;
        int q = (n - 1) / 2;
        for (int i = 0; i < p; i++) {
            res += v[n - 1 - i];
        }
        for (int i = 0; i < q; i++) {
            res -= v[i];
        }
    }

    cout << res << endl;
    return 0;
}
