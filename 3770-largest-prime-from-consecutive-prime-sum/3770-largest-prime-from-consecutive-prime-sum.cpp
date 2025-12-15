class Solution {
public:
    vector<bool>primes;
    void sieve(int n){
        primes.resize(n + 1, true);
        primes[0] = primes[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(primes[i]){
                for(int j = i * i; j <= n; j += i){
                    primes[j] = false;
                }
            }
        }
    }
    typedef long long ll;
    int largestPrime(int n) {
        sieve(n + 1);
        unordered_set<ll>st;
        ll sum = 0;
        ll ans = 0;
        for(int i = 2; i <= n; i++){
            if(primes[i]){
                sum += i;
                st.insert(sum);
                if(st.find(i) != st.end())ans = i;
            }
        }
        return ans;
    }
};