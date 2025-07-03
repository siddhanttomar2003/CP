typedef long long ll;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int op = log2(k);
        int increments = 0;
        while (k > 1LL) {
            if ((1LL << op) == k) op--;
            ll last = 1LL << op; 
            if (operations[op] == 1) increments++;
            k -= last;
            op = log2(k);
        }
        return (char)(97 + (increments % 26));
    }
};
