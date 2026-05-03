class Solution {
public:
    bool rotateString(string s, string g) {
        string a = s + s;
        int n = a.size(), m = g.size();
        if(s.size() != g.size())return false;
        int i = 0, j = 0;
        while(i < n && j < m){
            int prev = i;
            while(j < m && a[i] == g[j]){
                i++;
                j++;
            }
            if(j == m)return true;
            i = prev + 1;
            j = 0;
        }
        return false;
    }
};