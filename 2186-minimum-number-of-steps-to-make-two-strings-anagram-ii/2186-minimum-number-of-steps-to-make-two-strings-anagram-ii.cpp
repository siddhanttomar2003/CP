class Solution {
public:
    int minSteps(string s, string t) {
        int count=0;
        int hash1[26]={0}; int hash2[26]={0};
        int n=s.length();int m=t.length();
        for(int i=0;i<n;i++){hash1[s[i]-97]++;}
        for(int i=0;i<m;i++){hash2[t[i]-97]++;}
        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i])count+=abs(hash1[i]-hash2[i]);
        }
        return count;
       
    }
};