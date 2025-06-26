typedef long long ll;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        ll curr = 0;
        ll take = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            int sign = s[i] - 48;
            if(sign && take <= 32){
                 ll num = curr | ((1*1ll) << take);
                 if(num <= (ll)k){
                      curr = num;
                      take ++;
                 }
            }
            else if(sign == 0) {
                take ++;
            }
            // cout<<curr<<endl;
        }
        return take;
    }
};