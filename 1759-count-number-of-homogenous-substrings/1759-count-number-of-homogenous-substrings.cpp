class Solution {
public:
    typedef long long ll;
    const int m = 1e9 + 7;
    int countHomogenous(string s) {
        long long ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            long long curr = 1;
            while(i + 1 < n && s[i] == s[i + 1]){
                curr ++;
                i ++;
            }
            long long tot = (curr * (curr + 1*1ll)) / 2*1ll;
            ans = (ans + tot) % m;
        }
        return ans;
    }
};