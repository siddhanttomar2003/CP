class Solution {
public:
    int countOdds(int low, int high) {
        if(high & 1){
            if(low & 1)return (high - low + 1) / 2 + 1;
            else return (high - low + 1) / 2;
        }
        else {
            if(low & 1){
                return (high - low + 1) / 2;
            }
            else {
                return (high - low) / 2;
            }
        }
        return 0;
    }

};