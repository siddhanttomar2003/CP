class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
        return false;
    }
    int vowelConsonantScore(string s) {
        int v = 0;
        int n = s.size();
        int c = 0;
        for(auto it : s){
            if(isVowel(it))v++;
            else if(it >= 97 && it <= 125)c++;
        }
        if(c == 0)return 0;
        return v / c;
    }
};