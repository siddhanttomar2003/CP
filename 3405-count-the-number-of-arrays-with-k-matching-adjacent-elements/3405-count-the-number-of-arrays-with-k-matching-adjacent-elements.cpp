class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const int mod = 1e9 + 7;
        if (k > n - 1) return 0;
        vector<long long> inv(k + 1, 1);
        for (int i = 2; i <= k; i++) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        long long mid = 1;
        int minval = min(k, n - 1 - k);
        for (int i = 1; i <= minval; i++) {
            mid = mid * (n - i) % mod;
            mid = mid * inv[i] % mod;
        }
        long long powerVal = 1;
        long long base = (m - 1) % mod;
        int exp = n - 1 - k;
        while (exp > 0) {
            if (exp % 2 == 1) powerVal = (powerVal * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        long long result = (mid % mod) * (m % mod) % mod;
        result = result * powerVal % mod;
        return (int)result;
    }
};