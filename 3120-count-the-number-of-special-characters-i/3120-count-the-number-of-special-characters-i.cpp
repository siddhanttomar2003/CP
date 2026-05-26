class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>s;
        for(int i=0;i<word.length();i++){
            if(word[i]>=97){
                for(int j=i;j<word.length();j++){
                    if(word[j]==word[i]-32)s.insert(word[i]);
                }
            }
            else {
                                for(int j=i;j<word.length();j++){
                    if(word[j]==word[i]+32)s.insert(word[j]);
                }
            }
        }
     return s.size();
 }
};