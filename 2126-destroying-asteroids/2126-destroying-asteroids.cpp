class Solution {
public:
    typedef long long ll;
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(), a.end());
        ll curr = mass;
        ll n = a.size();
        for(ll i = 0; i < n; i++){
            if(curr >= a[i]){
                curr += a[i] * 1ll;
            }
            else return false;
        }
        return true;
    }
};