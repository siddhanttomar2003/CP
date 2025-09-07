class Solution {
public:
    typedef long long ll;
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 <= num2)return -1;
        for(ll i = 1; i <= 60; i++){
            ll lhs = num1 - (i * num2);
            if(lhs <= 0)break;
            int count = 0;
            for(ll j = 0; j <= 60; j++){
                if(lhs & (1LL << j)){
                    count++;
                }
            }
            if(count <= i  && i <= lhs)return i;
        }
        return -1;
    }
};