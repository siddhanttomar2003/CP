class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //calculate the total min elements
      sort(piles.begin(),piles.end());
      int sum=0;
      for(int i=piles.size()/3;i<piles.size();i=i+2){
         sum+=piles[i];
      }
      return sum;
    }
};