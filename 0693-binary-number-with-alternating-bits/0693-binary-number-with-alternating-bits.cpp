class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr = -1;
        while(n > 0){
            int sign = n & 1;
            if(curr == -1)curr = sign;
            else {
                if(curr != sign)curr = sign;
                else return false;
            }
            n /= 2;
        }
        return true;
    }
};