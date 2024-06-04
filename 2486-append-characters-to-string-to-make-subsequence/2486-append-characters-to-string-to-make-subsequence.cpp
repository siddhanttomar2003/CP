class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int m=s.length();
        int n=t.length();
       while(true){

            if(s[i]==t[j]){
                i++;j++;
            }
            else {
                i++;
            }
            if(i==m)break;
       }
        return n-j;
    }
};