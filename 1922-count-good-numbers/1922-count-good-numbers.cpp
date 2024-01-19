class Solution {
public:
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;
         long long e=5;
         long long ans1=1;
         long long ans2=1;
         long long o=4;
         while(odd>0){
             if(odd&1){
              ans1=(ans1*o)%1000000007;
             }
             o=(o*o)%1000000007;
             odd>>=1;
         }
         while(even>0){
             if(even&1){
                 ans2=(ans2*e)%1000000007;
             }
             e=(e*e)%1000000007;
             even>>=1;
         }
         int f=(ans1*ans2)%1000000007;
         return f;

    }
};