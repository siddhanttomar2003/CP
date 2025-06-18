typedef long long ll ;
class Solution {
public:
    ll cal(ll n, ll r){
        ll res=1;
        for(int i=0;i<r;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    int uniquePaths(int m, int n) {
       ll t=m+n-2;
       ll mini=min(n-1,m-1);
       return cal(t,mini);
    }
};