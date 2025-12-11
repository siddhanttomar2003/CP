class Solution {
public:
    typedef long long ll;
    bool check(ll mid, int n, vector<int>&b){
        int m = b.size();
        ll count = 0;
        ll curr = 0;
        for(auto it : b){
            curr += it;
            if(curr >= mid){
                curr -= mid;
                count++;
            }
        }
        return count >= n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        sort(batteries.begin(), batteries.end());
        ll s = 0;
        ll e = 1e15;
        ll ans = 0;
        while(s <= e){
            ll mid = s + (e - s) / 2;
            if(check(mid, n, batteries)){
                s = mid + 1;
                ans = mid;
            }
            else e = mid - 1;
        }
        return ans;
    }
};