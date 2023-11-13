class Solution {
public:
    string sortVowels(string s) {
        vector<char>v;
        vector<int>pos;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                v.push_back(s[i]);
                pos.push_back(i);
        }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<pos.size();i++){
            s[pos[i]]=v[i];
        }
        return s;

    }
};