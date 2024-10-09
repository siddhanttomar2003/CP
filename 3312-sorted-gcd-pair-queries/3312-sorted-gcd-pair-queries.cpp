const int N = 5e4+2;
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<long long>pre(N,0);
        vector<long long>cnt(N,0);
        vector<long long>pref(N,0);
        int n = (int)nums.size();
        for(auto &x : nums) {
            pre[x]++;
            cnt[x]++;
        }
        for(int i = 2 ; i < N ; i++) {          
            for(int j = 2 * i ; j < N ; j += i) {
                pre[i] += cnt[j];
            }
        }
        long long total = 0;
        for(int i = 2 ; i < N ; i++) {
            pref[i] = (pre[i] * (pre[i]-1))/2LL;
        }
        for(int i = N-1 ; i >= 2 ; i--) {
            for(int j = 2 * i ; j < N ; j += i) {
                pref[i] -= pref[j];
            }
            total += pref[i];
        }
        long long all = (n *1LL* (n - 1))/2LL;
        pref[1] = all - total;
        for(int i = 1 ; i < N ; i++) {
            pref[i] += pref[i-1];
        }
        vector<int>ans;
        int mx = *max_element(nums.begin(),nums.end());
        for(auto &x : queries) {
            ++x;
            int l = 0;
            int r = mx;
            while(r > l + 1) {
                int m = (l+r) >> 1;
                if(pref[m] >= x) {
                    r = m;
                }  else {
                    l = m;
                }
            }
            ans.push_back(r);
        }
        return ans;
    }
};