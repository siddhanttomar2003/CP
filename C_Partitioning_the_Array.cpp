#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Function to find all divisors of n
vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// Function to check if all subarrays are identical when replaced by their remainders modulo m
bool checkSubarrays(const vector<int>& a, int k, int m) {
    int n = a.size();
    vector<int> firstSubarray(k);
    for (int i = 0; i < k; ++i) {
        firstSubarray[i] = a[i] % m;
    }
    for (int i = k; i < n; i += k) {
        for (int j = 0; j < k; ++j) {
            if ((a[i + j] % m) != firstSubarray[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> divisors = getDivisors(n);
        int points = 0;

        for (int k : divisors) {
            if (k == n) continue; // Skip the case where k == n
            bool valid = false;
            for (int m = 2; m <= 100; ++m) { // Limit m to 100 for practicality
                if (checkSubarrays(a, k, m)) {
                    valid = true;
                    break;
                }
            }
            if (valid) {
                points++;
            }
        }

        cout << points+1 << "\n";
    }

    return 0;
}