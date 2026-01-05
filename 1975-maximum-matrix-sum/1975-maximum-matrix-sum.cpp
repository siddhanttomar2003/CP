class Solution {
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll neg = 0;
        ll mini_neg = 1e9;
        ll sum = 0;
        ll zero = 0;
        for(auto it : matrix){
            for(auto it2 : it){
                if(it2 < 0){
                    neg++;
                }
                else if(it2 == 0)zero++;
                if(it2 != 0)
                mini_neg = min((ll)abs(it2), mini_neg);
                sum += abs(it2);
            }
        }
        if(neg & 1 && !zero)return sum - 2 * 1ll * mini_neg;
        return sum;
    }
};