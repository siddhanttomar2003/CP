class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;int j=0;
        while(j<str2.size() && i<str1.size()){
            if(str2[j]=='a' && (str1[i]=='a' || str1[i]=='z')){
                i++;j++;
            }
                else if(str2[j]==str1[i]+1 || str2[j]==str1[i]){
                    i++;j++;
                }
            else i++;
        }
        return j==str2.size();
    }
};