class Solution {
public:
    typedef long long ll;
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n = h.size();
        sort(h.begin(), h.end());
        int times = k;
        ll ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(times > 0){
                ans += max(0, h[i] - (k - times));
                times--;
            }
            else break;
        }
        return ans;
    }
};