class Solution {
public:
    typedef long long ll;
    bool isPowerOfThree(int n) {
        ll i = 0;
        while(pow(3LL, i) < n){
            i++;
        }
        if(pow(3LL, i) == n)return true;
        return false;
    }
};