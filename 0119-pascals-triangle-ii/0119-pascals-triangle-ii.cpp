typedef long long ll;
class Solution {
public:
    ll cal(ll n , ll r){
        ll sum = 1;
        for(ll i = 0; i < r ; i++){
            sum *= (n-i);
            sum /= (i+1);
        }
        return sum;
    }
    vector<int> getRow(int rowIndex) {
       vector<int>  ans;
       for(ll i = 0 ; i <= rowIndex ; i++){
             ans.push_back(cal(rowIndex  , min(i , rowIndex  - i)));
       }
       return ans;
    }
};