class Solution {
public:
    int smallestNumber(int n) {
        int i=0;
        int curr=0;
        while(n>0){
          curr+=(pow(2,i));
          n/=2;
          i++;
        }
        return curr;
    }
};