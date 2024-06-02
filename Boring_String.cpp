#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inint(x) int x; cin >> x;
#define instr(x) string x; cin >> x;
#define rep(i, n, k) for (int i = k; i < n; ++i)
#define repa(it, mp) for (auto it = mp.begin(); it != mp.end(); ++it)

int32_t main()
{
    fastio();
    
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    
    int t;
    cin >> t;
    while (t--)
    {
        inint(n);
        instr(x);
        map<string, int> mp;
        
        // Initialize the current substring with the first character of the string
        string curr(1, x[0]);
         int ans = 0;
        rep(i, n, 1) {
            if (x[i] != curr.back()) {
                mp[curr]++;
                curr = x[i];
            } else {
                curr += x[i];
                if(curr.length()>2){
                    int s=curr.length();
                    ans=max(ans,s-1);
                }
            }
        }
        mp[curr]++;  // Include the last substring
          if(curr.length()>2){
                    int s=curr.length();
                    ans=max(ans,s-1);
                }
                
        repa(it, mp) {
            if (it->second > 1) {
                ans = max(ans, (int)it->first.size());
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
