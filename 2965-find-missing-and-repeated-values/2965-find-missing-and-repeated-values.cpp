typedef long long ll;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        ll size = grid.size();
        ll n = size * size;
        ll sum = (n * (n + 1))/2;
        ll ac_sum = 0;
        ll sum2 = (n * (n + 1) * (2 * n + 1))/6;
        ll ac_sum2 = 0;
        for(auto it : grid){
            for(auto it2 : it){
                ac_sum += it2;
                ac_sum2 += (it2 * it2);
            }
        }
        ll rhs1 = sum - ac_sum;
        ll rhs2 = sum2 - ac_sum2;
        ll rhs3 = rhs2 / rhs1;
        int missing = (rhs3 + rhs1)/2;
        int twice = rhs3 - missing;
        return {twice , missing};
    }
};