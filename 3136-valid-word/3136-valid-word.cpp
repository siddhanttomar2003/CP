class Solution {
public:
    bool isVowel(char c){
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    bool isValid(string word) {
        int size = word.size();
        if(size <= 2)return false;
        bool vowel = false;
        bool cons = false;
        for(auto it : word){
            if(isalnum(it)){
                if(isalpha(it)){
                    char c = it;
                    c = toupper(c);
                    if(isVowel(c)){
                        vowel = true;
                    }
                    else 
                    {
                        cons = true;
                    }
                }
            }
            else return false;
        }
        return vowel && cons;
    }
};