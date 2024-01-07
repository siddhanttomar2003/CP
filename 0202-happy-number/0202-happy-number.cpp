class Solution {
public:
    bool isHappy(int n) {
       set<int>s;
       while(n!=1){
           int newn=0;
           while(n>0){
           int last_digit=n%10;
           newn+=last_digit*last_digit;
           n/=10;
           }
           if(s.find(newn)!=s.end())return false;
           s.insert(newn);
           n=newn;
       }
       return true;
    }
};