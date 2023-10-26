class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
/* we need to check how many of them are at the odd posn and how many are at the 
even posn  . then we know that for moving the disc at even posn will not cost any but for moving the odd ones will cost 1
 */
 int e=0;int o=0;
 for(int i=0;i<position.size();i++){
     if(position[i]%2!=0){
         o++;
     }
     else e++;
 }
 return min(o,e);

    }
};