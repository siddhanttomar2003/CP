class Solution {
public:
    char kthCharacter(int k) {
        int op = log2(k);
        int increments = 0;
        while(k > 1){
            if(pow(2, op) == k) op--;
            int last = pow(2, op);
            k -= last;
            op = log2(k);
            increments++;
        }
        return 'a' + increments;
    }
};