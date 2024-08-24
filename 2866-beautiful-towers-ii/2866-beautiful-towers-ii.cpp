typedef long long int ll;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll n = maxHeights.size();
        
        stack<int> s;
        vector<ll> prv(n, 0), nxt(n, 0);
        vector<ll> lft(n, 0), rgt(n, 0);
        
        for (int j = 0; j < n; j ++) {
            while (!s.empty() && maxHeights[s.top()] >= maxHeights[j]) 
                s.pop();
            
            prv[j] = s.empty()? -1 : s.top();
            s.push(j);
        }
        
        while (!s.empty()) s.pop();
        
        for (int j = n-1; j >= 0; j --) {
            while (!s.empty() && maxHeights[s.top()] >= maxHeights[j]) 
                s.pop();
            
            nxt[j] = s.empty()? n : s.top();
            s.push(j);
        }
        
        for (ll j = 0; j < n; j ++) {
            lft[j] = maxHeights[j];
            
            if (j == 0) continue;
            
            if (maxHeights[j] >= maxHeights[j-1]) 
                lft[j] += lft[j-1];
            else 
                lft[j] += (j - prv[j] - 1) * maxHeights[j] + (prv[j] < 0? 0 : lft[prv[j]]);
        }
        
        for (ll j = n-1; j >= 0; j --) {
            rgt[j] = maxHeights[j];
            
            if (j == n-1) continue;
            
            if (maxHeights[j] >= maxHeights[j+1]) 
                rgt[j] += rgt[j+1];
            else 
                rgt[j] += (nxt[j] - j - 1) * maxHeights[j] + (nxt[j] >= n? 0 : rgt[nxt[j]]);
        }
        
        ll ans = 0;
        for (int j = 0; j < n; j ++)
            ans = max(ans, lft[j] + rgt[j] - maxHeights[j]);
        
        return ans;
    }
};