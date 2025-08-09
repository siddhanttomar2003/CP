class Solution {
public:
    typedef long long ll;
    bool isPowerOfTwo(int n) {
        if(n == 0)return false;
        ll a = n;
        if(!(a & (a - 1)))return true;
        return false;
    }
};