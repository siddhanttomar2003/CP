class Solution {
public:
    typedef long long ll;
    int mirrorDistance(int n) {
        string a = to_string(n);
        reverse(a.begin(), a.end());
        int b = stoi(a);
        return abs(n - b);
    }
};