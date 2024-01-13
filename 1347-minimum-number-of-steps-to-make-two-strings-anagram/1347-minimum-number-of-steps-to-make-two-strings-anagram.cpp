class Solution {
public:
    int minSteps(string s, string t) {
        int hash1[26]={0};
        int hash2[26]={0};
        for(int i=0;i<s.length();i++){
            hash1[s[i]-97]++;
            hash2[t[i]-97]++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(hash1[i]>hash2[i])count+=hash1[i]-hash2[i];
        }
        return count;
    }
};