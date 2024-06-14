#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1000000007; // Example modulus value

ll binomial_expo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;cin>>t;
    while(t--){
    ll n;
    cin >> n;

    ll square = binomial_expo(n, 2, M);
    ll cube = binomial_expo(n, 3, M);
    
    ll result = (((4 * cube % M + 3 * square % M - n) % M) + M) % M; 
    result = (result * 2022) % M; 
    result = (result * binomial_expo(6, M - 2, M)) % M; 
    cout << result << endl;
   }

    return 0;
}
