#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to perform modular exponentiation
int modPow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to find all prime factors of n
void findPrimeFactors(vector<int> &factors, int n) {
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
}

// Function to check if a number is a primitive root modulo p
bool isPrimitiveRoot(int x, int p) {
    int phi = p - 1;
    vector<int> factors;
    findPrimeFactors(factors, phi);

    for (int factor : factors) {
        if (modPow(x, phi / factor, p) == 1) {
            return false;
        }
    }
    return true;
}

// Function to count the number of primitive roots modulo p
int countPrimitiveRoots(int p) {
    int count = 0;
    for (int x = 1; x < p; x++) {
        if (isPrimitiveRoot(x, p)) {
            count++;
        }
    }
    return count;
}

int main() {
    int p;
    cin >> p;
    cout << countPrimitiveRoots(p) << endl;
    return 0;
}
