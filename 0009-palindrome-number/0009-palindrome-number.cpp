class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
         long long int reverse=0;
         int n=x;
        while(n>0){
            int ld=n%10;;
            reverse=(reverse*10)+ld;
            n=n/10;
        }
        if(reverse==x)return true;
        else return false;
    }
};