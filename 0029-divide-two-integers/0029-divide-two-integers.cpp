class Solution {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        int sign = 1;
        if(dividend < 0 && divisor > 0)sign = -1;
        if(dividend > 0 && divisor < 0)sign = -1;
        int i = 31;
        ll quotient = 0;
        ll did = abs(dividend);
        ll div = abs(divisor);
        while(i >= 0){
            if((div << i) <= did){
                did -= (div << i);
                quotient += (1LL << i);
            }
            i --;
        }
        return quotient * sign;
    }
};