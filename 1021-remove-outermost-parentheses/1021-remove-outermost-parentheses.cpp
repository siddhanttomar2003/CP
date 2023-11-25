class Solution {
public:
    string removeOuterParentheses(string s) {
      string st;
      int n=s.length();
     int count=0;
     for(int i=0;i<n;i++){
         if(s[i]=='('){
             if(count>=1)st+=s[i];
             count++;
         }
         else {
        if(count>1)st+=s[i];
        count--;
         }
         
     }
     return st;

    }
};