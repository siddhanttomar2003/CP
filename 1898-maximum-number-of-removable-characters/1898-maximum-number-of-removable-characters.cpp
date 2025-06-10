class Solution {
public:
    bool check(int m, string& s, string& p, vector<int>& r) {
        unordered_set<int> st;
        for (int i = 0; i < m; i++)
            st.insert(r[i]);
        int i = 0, j = 0;
        while (j < p.size() && i < s.size()) {
            if (s[i] == p[j] && st.find(i) == st.end()) {
                i++;
                j++;
            } else
                i++;
        }
        return j == p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int i = 1;
        int j = removable.size();
        int ans = 0;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (check(m, s, p, removable)) {
                ans = m;
                i = m + 1;
            } else
                j = m - 1;
        }
        return ans;
    }
};