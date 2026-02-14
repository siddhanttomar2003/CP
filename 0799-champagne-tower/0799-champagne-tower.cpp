class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
         vector<double>last = {double(poured)};
         for(int i = 1; i <= query_row; i++){
            vector<double>curr;
            for(int j = 0; j <= i; j++){
                double add = 0;
                if(j == 0){
                    if(last[j] - 1 > 0) add += (last[j] - 1) / 2.00;
                } 
                else if(j == i){
                    if(last[j - 1] - 1 > 0) add += (last[j - 1] - 1) / 2.00;
                }
                else {
                    if(last[j] - 1 > 0) add += (last[j] - 1) / 2.00;
                    if(last[j - 1] - 1 > 0) add += (last[j - 1] - 1) / 2.00;
                }
                curr.push_back(add);
            }
            last = curr;
         }
         return min(1.00, last[query_glass]);
    }
};