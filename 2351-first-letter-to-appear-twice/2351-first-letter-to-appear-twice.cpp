class Solution {
public:
    char repeatedCharacter(string s) {
        set<char>m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end())return s[i];
            else m.insert(s[i]);
        }
         return '0';
    }
};