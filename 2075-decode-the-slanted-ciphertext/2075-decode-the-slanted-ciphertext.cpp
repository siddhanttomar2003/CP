class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        string ans = "";
        int n = rows;
        int m = e.size() / n;
        int j = 0;
        while(j < m){
            int i = 0;
            int c = j;
            while(i < n && c < m){
                ans += e[i * m + c];
                i++;
                c++;
            }
            j++;
        }
        while(ans.size() > 0 && ans.back() == ' ')ans.pop_back();
        return ans;
    }
};