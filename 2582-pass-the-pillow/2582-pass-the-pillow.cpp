class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle=time/(n-1);
        if(cycle&1){
          // right ->left
           if(time%(n-1)==0){
            return n;
           }
           return n-(time%(n-1));
        }
        else {
            if(time%(n-1)==0)return 1;
            return time%(n-1)+1;
        }
    }
};