class Solution {
public:
    bool isPalindrome(string s) {
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>=97&&s[i]<=122||s[i]>=48&&s[i]<=57){
                s[j]=s[i];
                j++;
            }
            else if(s[i]>=65&&s[i]<=90){
                s[j]=s[i]+32;
                j++;
            }
        }
        s.erase(s.begin()+j,s.end());
        string t=s;
        reverse(s.begin(),s.end());
        return t==s;
       
    }
};