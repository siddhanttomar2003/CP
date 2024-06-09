class Solution {
public:
    int numberOfChild(int n, int k) {
      int op=k/(n-1);
      if(op&1){
       
        return  n-1-k%(n-1);
      }
      else return  k%(n-1);
    }
};