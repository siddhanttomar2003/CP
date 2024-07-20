#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to find the minimum time to solve all puzzles
int minTimeToSolvePuzzles(vector<int>& time, vector<int>& search, int k) {
    int n = time.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 time to solve 0 puzzles

    for (int i = 1; i <= n; ++i) {
        // Case 1: Solve the i-th puzzle on his own
        dp[i] = dp[i - 1] + time[i - 1];

        // Case 2: Search in the book and get answers for next k puzzles
        for (int j = 0; j < k && i + j <= n; ++j) {
            dp[i + j] = min(dp[i + j], dp[i - 1] + search[i - 1]);
        }
    }

    return dp[n];
}

int main() {
    // Example input
    vector<int> time = {4, 2, 5, 6, 3};
    vector<int> search = {2, 3, 1, 4, 2};
    int k = 2;

    int result = minTimeToSolvePuzzles(time, search, k);
    cout << "Minimum time to solve all puzzles: " << result << endl;

    return 0;
}
