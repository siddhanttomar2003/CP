class Solution {
public:
    bool pal(string &s, int i, int j){
        while(i < j){
            if(s[i] == s[j]){
                i++;j--;
            }
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j){
            if(s[i] == s[j]){
                i++;j--;
            }
            else {
                i++;
                bool check = pal(s, i, j);
                i--;
                j--;
                check |= pal(s, i, j);
                return check;
            }
        }
        return true;
    }
};