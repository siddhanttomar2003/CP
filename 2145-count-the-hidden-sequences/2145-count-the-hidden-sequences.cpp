class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
          int curr_s=lower,curr_e=upper;
          int range_s=lower,range_e=upper;
          int n=differences.size();
          for(int i=0;i<n;i++){
           int d=differences[i];
           curr_s+=differences[i];
           curr_e+=differences[i];
           if(curr_s>upper || curr_e<lower)return 0;
           range_s=max(range_s,curr_s);
           range_e=min(range_e,curr_e);
          }
          if(range_e<range_s)return 0;
          return range_e-range_s+1;
    }
};