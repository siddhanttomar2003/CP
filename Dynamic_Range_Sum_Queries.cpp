// #include <iostream>
// #include <cmath>
// #include<bits/stdc++.h>
// using namespace std;

// const int M = 10000 + 7;

// long long countNumbersWithAtLeastTwoZeros(int N) {
//     if (N < 2) return 0;
//     long long totalNumbers = 9 * pow(10, N-1);
//     long long numbersWithLessThanTwoZeros = 0;
//     numbersWithLessThanTwoZeros += pow(9, N);
//     numbersWithLessThanTwoZeros += (N - 1) * pow(9, N - 1);
//     long long ans = totalNumbers - numbersWithLessThanTwoZeros;

//     return ans % M;
// }

// int main() {
//     int N;
//     std::cin >> N;

//     std::cout << countNumbersWithAtLeastTwoZeros(N) << std::endl;

//     return 0;
// }
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to count the number of disqualified players
int countDisqualifiedPlayers(int N, int K, const vector<pair<int, int>>& records) {
    unordered_map<int, unordered_map<int, int>> playerBallCount;
    unordered_map<int, bool> disqualified;

    for (const auto& record : records) {
        int playerId = record.first;
        int ballNumber = record.second;

        playerBallCount[playerId][ballNumber]++;
        
        // Disqualify immediately if K == 0
        if (K == 0 && playerBallCount[playerId][ballNumber] > 0) {
            disqualified[playerId] = true;
        } else if (K > 0 && playerBallCount[playerId][ballNumber] > K) {
            disqualified[playerId] = true;
        }
    }

    return disqualified.size();
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> records(N);
    for (int i = 0; i < N; ++i) {
        cin >> records[i].first >> records[i].second;
    }

    cout << countDisqualifiedPlayers(N, K, records) << endl;

    return 0;
}


