#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<unsigned long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

 
    unsigned long long threshold = 1;
    for(int i = 0; i < K; i++){
        threshold *= 10ULL;
    }

    unsigned long long cur = 1;
    for(int i = 0; i < N; i++){
        unsigned long long ai = A[i];

        if (cur > (threshold - 1) / ai) {
            cur = 1;
        } else {
            cur *= ai;
        }
    }

    cout << cur << "\n";
    return 0;
}
