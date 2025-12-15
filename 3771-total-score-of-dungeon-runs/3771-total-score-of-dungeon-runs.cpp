class Solution {
public:
    typedef long long ll;
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<ll>suff(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            suff[i] = suff[i + 1] + damage[i];
        }
        ll count = 0;
        ll ex = 0;
        for(int i = n - 1; i >= 0; i--){
            ll req = requirement[i];
            // cout << suff[i] << " ";
            int s = 0, e = i;
            ll idx = -1;
            while(s <= e){
                int mid = s + (e - s) / 2;
                if(suff[mid] + req - ex > hp) s = mid + 1;
                else {
                    idx = mid;
                    e = mid - 1;
                }
            }
            if(idx != -1){
                 count += (i - idx + 1);
                //  cout << count << " ";
            }
            // else cout << "Not Possible" << " ";
            
            ex += damage[i];
        }
        return count;
    }
};