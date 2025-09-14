class Solution {
public:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        map<string,int>mp1;
        map<string,int>mp2;
        set<string>st;
        for(auto it : wordlist)st.insert(it);
        int n = wordlist.size();
        for(int i = 0; i < n; i++){
           string a = "";
           string b = "";
           for(auto it : wordlist[i])a += tolower(it);
           for(auto it : wordlist[i]){
                if(is_vowel(tolower(it))){
                    b += '#';
                }
                else b += tolower(it);
           }
           if(mp1.find(a) == mp1.end())mp1[a] = i;
           if(mp2.find(b) == mp2.end())mp2[b] = i;
        }
        vector<string>ans;
        for(auto it : queries){
            string a = "";
            string b = "";
            for(auto it2 : it){
                a += tolower(it2);
            }
            for(auto it2 : it){
                if(is_vowel(tolower(it2))){
                    b += '#';
                }
                else b += tolower(it2);
            }
            if(st.find(it) != st.end())ans.push_back(it);
            else if(mp1.find(a) != mp1.end())ans.push_back(wordlist[mp1[a]]);
            else if(mp2.find(b) != mp2.end())ans.push_back(wordlist[mp2[b]]);
            else ans.push_back("");
        }
        return ans;
    }
};