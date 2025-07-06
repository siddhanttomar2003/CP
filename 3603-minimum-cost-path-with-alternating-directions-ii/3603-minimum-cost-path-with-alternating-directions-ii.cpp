typedef long long ll;
class Solution {
public:
    vector<vector<vector<ll>>>dp;
    ll cal(vector<vector<int>>&w, int i , int j , int m, int n , int state){
        if(i == m && j == n)return 0;
        if(i == m + 1 || j == n + 1)return 1e12;
        if(dp[i][j][state] != -1)return dp[i][j][state];
        ll curr = 1e12;
        if(state & 1){
            curr = min(curr, ((i + (ll)2) * (j + (ll)1)) + cal(w, i + 1, j, m, n, state ^ 1));
            curr = min(curr,((i + (ll)1) * (j + (ll)2)) + cal(w, i , j + 1, m, n, state ^ 1));
        }
        else {
            curr = (ll)w[i][j] + cal(w, i, j, m, n, state ^ 1);
        }
        return dp[i][j][state] = curr; 
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        dp.assign(m, vector<vector<ll>>(n, vector<ll>(2, -1)));
        int state = 1;
        ll i = 0 , j = 0;
        return cal(waitCost, i, j, m - 1, n - 1, state) + (ll)1;
    }
};