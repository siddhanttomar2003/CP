typedef long long ll;
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        map<ll,set<ll>>mp_x,mp_y;
        ll mini_x = 1e9,mini_y = 1e9;
        ll maxi_x = -1e9,maxi_y = -1e9;
        for(auto it : coords){
            mini_x = min(mini_x , (ll)it[0]);
            maxi_x = max(maxi_x , (ll)it[0]);
            mini_y = min(mini_y , (ll)it[1]);
            maxi_y = max(maxi_y , (ll)it[1]);
            mp_x[it[0]].insert(it[1]);
            mp_y[it[1]].insert(it[0]);
        }
        ll maxi = -1;
        for(auto it : mp_x){
            if(it.second.size() > 1)
            {
                ll s = *mp_x[it.first].begin();
                ll e = *mp_x[it.first].rbegin();
                ll base = e-s;
                ll h1 = abs(mini_x-it.first);
                ll h2 = abs(maxi_x-it.first);
                ll op1 = base * h1;
                ll op2 = base * h2;
                maxi = max({maxi, op1 , op2});
            }
        }

          for(auto it : mp_y){
            if(it.second.size() > 1)
            {
                ll s = *mp_y[it.first].begin();
                ll e = *mp_y[it.first].rbegin();
                ll base = e-s;
                ll h1 = abs(mini_y-it.first);
                ll h2 = abs(maxi_y-it.first);
                ll op1 = base * h1;
                ll op2 = base * h2;
                maxi = max({maxi, op1 , op2});
            }
        }
        return maxi;
    }
};