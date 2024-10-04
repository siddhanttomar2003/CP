class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
      int times=0;
      for(int i=log2(k);i>=0;i--){
        if(k> 1LL<<i){
            k-= 1LL<<i;
            times+=operations[i];
        }
      }
      return 'a'+ times %26;

    }
};