class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> vis(n, 0);
        string ans = "";
        int last = 0;
        for (char i = 'a'; i <= 'z'; i++) {
            int l = last;
            while (l - 1 >= 0 && s[l - 1] <= i || (l-1>=0 && vis[l-1])) {
                if(s[l-1]<=i && !vis[l-1]){
                vis[l - 1] = 1;
                ans += s[l - 1];
                }
                l--;
            }
            int pos_last = last;
            for (int j = last; j < n; j++) {
                if (s[j] == i) {
                    ans += i;
                    vis[j] = 1;
                    pos_last = j;
                }
            }
            last = pos_last;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (!vis[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};