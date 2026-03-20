class Solution {
public:
    typedef long long ll;
    ll cal(map<int, int> &mp){
        ll prev = -1e12;
        ll mini = 1e12;
        if(mp.size() == 1)return 0;
        for(auto it : mp){
            ll num = it.first;
            mini = min(mini, num - prev);
            prev = it.first;
        }
        return mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        map<ll, int>mp;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>ans(n - k + 1);
        for(int i = 0; i < n; i++){
            if(i + k <= n){
                int j = 0;
                map<int, int>mp;
                while(j < k){
                    for(int l = i; l < i + k; l++){
                        mp[grid[l][j]]++;
                    }
                    j++;
                }
                ans[i].push_back(cal(mp));
                int p = 0;
                while(j < m){
                    for(int l = i; l < i + k; l++){
                        mp[grid[l][p]]--;
                        if(mp[grid[l][p]] == 0)mp.erase(grid[l][p]);
                        mp[grid[l][j]]++;
                    }
                    p++;
                    ans[i].push_back(cal(mp));
                    j++;
                }
            }
        }
        return ans;
    }
};