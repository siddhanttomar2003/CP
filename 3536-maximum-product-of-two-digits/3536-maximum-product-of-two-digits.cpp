class Solution {
public:
    int maxProduct(int n) {
        int maxi1=0;
        int maxi2=0;
        while(n>0){
            int d=n%10;
            if(d>=maxi1){
                maxi2=maxi1;
                maxi1=d;
            }
            else if(d>maxi2){
                maxi2=d;
            }
            n/=10;
        }
        return maxi1*maxi2;
    }
};