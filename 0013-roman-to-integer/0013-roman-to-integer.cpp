class Solution {
public:
    int romanToInt(string s) {
        map<string, int> mp;
        mp["IV"] = 4, mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
        mp["III"] = 3, mp["II"] = 2;
        mp["X"] = 10, mp["I"] = 1, mp["V"] = 5;
        mp["L"] = 50, mp["C"] = 100, mp["D"] = 500, mp["M"] = 1000;
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i + 2 < n) {
                string curr = "";
                curr += s[i];
                curr += s[i + 1];
                curr += s[i + 2];
                if (mp.find(curr) != mp.end()) {
                    ans += mp[curr];
                    i += 2;
                    continue;
                }
            }
            if (i + 1 < n) {
                string curr = "";
                curr += s[i];
                curr += s[i + 1];
                if (mp.find(curr) != mp.end()) {
                    ans += mp[curr];
                    i++;
                    continue;
                }
            }
            string curr = "";
            curr += s[i];
            ans += mp[curr];
        }
        return ans;
    }
};