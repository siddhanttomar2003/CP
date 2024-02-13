class Solution {
public:
    bool palendrome(string s){
        int i=0;
        int e=s.length()-1;
        while(i<e){
            if(s[i]!=s[e])return false;
            i++;e--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++){
            if(palendrome(words[i]))return words[i];
        }
        return ans;
    }
};