#include <iostream>
#include <vector>
using namespace std;

int countUniqueMarbleCounts(int N, int A, int B) {
    // Create a DP array initialized to false
    vector<bool> dp(N + 1, false);
    
    // Start with the initial number of marbles N
    dp[N] = true;
    
    // Iterate from N down to 0
    for (int i = N; i >= 0; --i) {
        if (dp[i]) {  // If dp[i] is true, transition to dp[i-A] and dp[i-B]
            if (i - A >= 0) dp[i - A] = true;
            if (i - B >= 0) dp[i - B] = true;
        }
    }
    
    // Count the number of true values in dp array
    int uniqueCount = 0;
    for (int i = 0; i <= N; ++i) {
        if (dp[i]) ++uniqueCount;
    }
    
    return uniqueCount;
}

int main() {
    int N, A, B;
    // cout << "Enter N, A, B: ";
    cin >> N >> A >> B;
    
    int result = countUniqueMarbleCounts(N, A, B);
    cout  << result-1 << endl;
    
    return 0;
}