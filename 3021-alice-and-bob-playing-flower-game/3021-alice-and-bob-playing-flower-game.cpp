class Solution {
public:
    long long flowerGame(int n, int m) {
       // if x+y is odd then alice will win else bob will win
       long long oddn;
       long long evenn;
       if(n&1){
           oddn=n/2+1;
           evenn=n/2;
        
       }
       else{
            oddn=n/2;
         evenn=n/2;
       }
       long long oddm;
       long long evenm;
       if(m&1){
           oddm=m/2+1;
           evenm=m/2;
       }
       else{
         oddm=m/2;
         evenm=m/2;  
       }
       return oddm*evenn+oddn*evenm;

    }
};