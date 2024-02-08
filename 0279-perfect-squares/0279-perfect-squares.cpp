class Solution {
public:
    bool isperfect_sq(int n){       
        int a=sqrt(n);
        return a*a==n;
    }
    int numSquares(int n) {
        // a number can be represented as sum of four square of integers if it is of
        // type 4a(8b+7) other wise it can be represented as sum of three sq of integers
        // but we have to keep check whether it is not a perfect sq or it can be reperesented in two
        if(isperfect_sq(n))return 1;
        for(int i=1;i*i<=n;i++){
            if(isperfect_sq(n-(i*i))){
                return 2;
            }
        } 
        int a=n;
        while(a%4==0){
            a/=4;
        }
        if(a%8==7)return 4;
         return 3;
    }
};