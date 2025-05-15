class Solution {
public:
    double res(double x, int n){
        double ans=1.00;
        while(n>0){
            if(n&1){
                ans*=x;
            }
            x*=x;
            n>>=1;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(n<0){
            x=1.00/x;
            n=abs(n);
        }
        return res(x,n);
    }
};
