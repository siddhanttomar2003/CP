const int m=1e9+7;
class Solution {
public:
    long long binomial_expo(long long a, long long b){
         long long  res=1;
         while(b){
            if(b&1){
                res=(res*a)%m;
            }
            a=(a*a)%m;
            b>>=1;
         }
         return res;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=(n+1)/2;
        long long  a= binomial_expo(5,even);
        long long  b=binomial_expo(4,odd);
        return (a*b)%m;
    }
};